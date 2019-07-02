#!/bin/bash

# CREATING CA CERTIFICATE
echo "Creating CA Certificate"

# Pass-in Variables
country=US
state=Seattle
locality="."
organization="."
organizationalunit="."
commonname="."
email="."

password=""

# CA Key
echo "Generating CA Key"
openssl genrsa -out rootCA.key 2048 

# CA Certificate
echo "Generating CA Certificate"
openssl req -x509 -config rootCA_openssl.conf -new -nodes -key rootCA.key -sha256 -extensions v3_ca -days 1024 -out rootCA.pem -passin pass:$password \
    -subj "/C=$country/ST=$state/L=$locality/O=$organization/OU=$organizationalunit/CN=$commonname/emailAddress=$email"




# REGISTERING CA CERTIFICATE
echo "Registering CA Certificate with AWS IoT"

registration_code_str=$(aws iot get-registration-code)  # registraton code / common name
registration_code="${registration_code_str:27:64}" # CHECK THIS: REGISTRATION CODE LENGTH MAY NOT BE THE SAME ALWAYS

openssl genrsa -out verificationCert.key 2048   # key pair for private key verification certificate
openssl req -new -key verificationCert.key -out verificationCert.csr -passin pass:$password \
    -subj "/C=$country/ST=$state/L=$locality/O=$organization/OU=$organizationalunit/CN=$registration_code/emailAddress=$email"  # Create CSR
            # DOUBLE-CHECK ON CHALLENGE PASSWORD INPUT

# Create Private Key Verification Certificate Using CSR
openssl x509 -req -in verificationCert.csr -CA rootCA.pem -CAkey rootCA.key -CAcreateserial -out verificationCert.pem -days 500 -sha256 

# Register CA Certificate
aws iot register-ca-certificate --ca-certificate file://rootCA.pem --verification-cert file://verificationCert.pem --set-as-active --allow-auto-registration --registration-config file://provisioning-template.json