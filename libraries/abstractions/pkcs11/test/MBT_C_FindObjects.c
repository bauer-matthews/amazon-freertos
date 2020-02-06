/*
 * Amazon FreeRTOS PKCS#11 V1.0.8
 * Copyright (C) 2019 Amazon.com, Inc. or its affiliates.  All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * http://aws.amazon.com/freertos
 * http://www.FreeRTOS.org
 */

 //------------------------------------------------------------------------------
 //
 // This code was auto-generated by a tool.
 //
 // Changes to this file may cause incorrect behavior and will be 
 // lost if the code is regenerated.
 //
 //-----------------------------------------------------------------------------

#include "iot_test_pkcs11_globals.h"

void C_FindObjects_normal_behavior()
{
    CK_SESSION_HANDLE hSession = xGlobalSession;
    CK_OBJECT_HANDLE phObject_val = 0;
    CK_OBJECT_HANDLE_PTR phObject = &phObject_val;
    CK_ULONG ulMaxObjectCount = 1;
    CK_ULONG pulObjectCount_val;
    CK_ULONG_PTR pulObjectCount = &pulObjectCount;

    CK_RV rv = pxGlobalFunctionList->C_FindObjects( hSession, phObject, ulMaxObjectCount, pulObjectCount );

    TEST_ASSERT_EQUAL( CKR_OK, rv );
}

void C_FindObjects_exceptional_behavior_0()
{
    CK_SESSION_HANDLE hSession = xGlobalSession;
    CK_OBJECT_HANDLE phObject_val = 0;
    CK_OBJECT_HANDLE_PTR phObject = &phObject_val;
    CK_ULONG ulMaxObjectCount = 1;
    CK_ULONG pulObjectCount_val;
    CK_ULONG_PTR pulObjectCount = &pulObjectCount;

    CK_RV rv = pxGlobalFunctionList->C_FindObjects( hSession, phObject, ulMaxObjectCount, pulObjectCount );

    TEST_ASSERT_EQUAL( CKR_OPERATION_NOT_INITIALIZED, rv );
}

void C_FindObjects_exceptional_behavior_1()
{
    CK_SESSION_HANDLE hSession = CK_INVALID_HANDLE;
    CK_OBJECT_HANDLE phObject_val = 0;
    CK_OBJECT_HANDLE_PTR phObject = &phObject_val;
    CK_ULONG ulMaxObjectCount = 1;
    CK_ULONG pulObjectCount_val;
    CK_ULONG_PTR pulObjectCount = &pulObjectCount;

    CK_RV rv = pxGlobalFunctionList->C_FindObjects( hSession, phObject, ulMaxObjectCount, pulObjectCount );

    TEST_ASSERT_EQUAL( CKR_SESSION_HANDLE_INVALID, rv );
}

void C_FindObjects_exceptional_behavior_2()
{
    CK_SESSION_HANDLE hSession = xGlobalSession;
    CK_OBJECT_HANDLE_PTR phObject = NULL_PTR;
    CK_ULONG ulMaxObjectCount = 0;
    CK_ULONG pulObjectCount_val;
    CK_ULONG_PTR pulObjectCount = &pulObjectCount;

    CK_RV rv = pxGlobalFunctionList->C_FindObjects( hSession, phObject, ulMaxObjectCount, pulObjectCount );

    TEST_ASSERT_EQUAL( CKR_ARGUMENTS_BAD, rv );
}

void C_FindObjects_exceptional_behavior_3()
{
    CK_SESSION_HANDLE hSession = xGlobalSession;
    CK_OBJECT_HANDLE phObject_val = 0;
    CK_OBJECT_HANDLE_PTR phObject = &phObject_val;
    CK_ULONG ulMaxObjectCount = 1;
    CK_ULONG pulObjectCount_val;
    CK_ULONG_PTR pulObjectCount = &pulObjectCount;

    CK_RV rv = pxGlobalFunctionList->C_FindObjects( hSession, phObject, ulMaxObjectCount, pulObjectCount );

    TEST_ASSERT_EQUAL( CKR_CRYPTOKI_NOT_INITIALIZED, rv );
}