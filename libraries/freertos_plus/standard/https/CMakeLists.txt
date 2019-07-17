afr_module()

set(src_dir "${CMAKE_CURRENT_LIST_DIR}/src")
set(inc_dir "${CMAKE_CURRENT_LIST_DIR}/include")
set(test_dir "${CMAKE_CURRENT_LIST_DIR}/test")

# Enable test access if building tests.
if(${AFR_IS_TESTING})
    list(APPEND extra_https_test_includes "${test_dir}/access")
endif()

afr_module_sources(
    ${AFR_CURRENT_MODULE}
    PRIVATE
        "${src_dir}/iot_https_client.c"
        "${src_dir}/iot_https_utils.c"
)

afr_module_include_dirs(
    ${AFR_CURRENT_MODULE}
    PUBLIC 
        "${inc_dir}"
        "$<${AFR_IS_TESTING}:${src_dir}>"
    PRIVATE
        ${extra_https_test_includes}
)

afr_module_dependencies(
    ${AFR_CURRENT_MODULE}
    PUBLIC
        AFR::common
        3rdparty::http-parser
)

# HTTPS Client test
afr_test_module()

afr_module_sources(
    ${AFR_CURRENT_MODULE}
    INTERFACE
        "${test_dir}/unit/iot_tests_https_client.c"
        "${test_dir}/unit/iot_tests_https_utils.c"
)

afr_module_include_dirs(
    ${AFR_CURRENT_MODULE}
    INTERFACE
        "${test_dir}/access"
)
afr_module_dependencies(
    ${AFR_CURRENT_MODULE}
    INTERFACE
        INTERFACE AFR::https
)
