FILESEXTRAPATHS:append := ":${THISDIR}/ptest"
SRC_URI += "file://run-ptest"

inherit ptest

fakeroot do_install_ptest() {
    if [ -n "${OE_QMAKE_QMAKE}" ]; then
        # qmake project
        B_PTEST=${B}
        mkdir -p ${B_PTEST}/tests
        cd ${B_PTEST}/tests
        ${OE_QMAKE_QMAKE} -o Makefile ${S}/tests
        oe_runmake
    else
        # cmake project
        B_PTEST=${WORKDIR}/build-ptest
        mkdir -p ${B_PTEST}
        cd ${B_PTEST}
        cmake \
            ${OECMAKE_GENERATOR_ARGS} \
            -DCMAKE_TOOLCHAIN_FILE=${WORKDIR}/toolchain.cmake \
            -DPython3_EXECUTABLE=${PYTHON} \
            ${EXTRA_OECMAKE} \
            -DQT_BUILD_STANDALONE_TESTS=ON \
            -DQT_ADDITIONAL_PACKAGES_PREFIX_PATH="${D}${QT6_INSTALL_LIBDIR}/cmake;${RECIPE_SYSROOT}/${QT6_INSTALL_LIBDIR}/cmake" \
            -DCMAKE_STAGING_PREFIX=${D}${prefix} \
            -DCMAKE_SKIP_RPATH=ON \
            ${S} \
            -Wno-dev
        ${CMAKE_VERBOSE} cmake --build ${B_PTEST} --target all
    fi

    # if any auto tests were build
    if [ -e "${B_PTEST}/tests/auto" ]; then
        install -d ${D}${PTEST_PATH}/tests
        cp -r ${B_PTEST}/tests/auto ${D}${PTEST_PATH}/tests

        # remove build files
        find ${D}${PTEST_PATH}/tests \
            \( -wholename "*/.*" -o -wholename "*autogen*" -o -iwholename "*cmake*" -o -name Makefile \) \
            -delete

        for f in $(find ${D}${PTEST_PATH} -name tst_* -executable); do
            test=${f##${D}${PTEST_PATH}/}
            testdir=$(dirname ${test})
            # tests may depend on files from sources
            cp -r ${S}/${testdir}/* ${D}${PTEST_PATH}/${testdir}
            echo ${test} >> ${D}${PTEST_PATH}/tst_list
        done
    fi
}

INSANE_SKIP:${PN}-ptest += "file-rdeps"

PACKAGESPLITFUNCS =+ "remove_ptest_debug"
remove_ptest_debug() {
    for i in $(find ${PKGD}${QT6_INSTALL_LIBDIR}/${BPN}/ptest/tests/auto -name .debug); do
        rm -rf $i
    done
}
