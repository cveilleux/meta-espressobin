require u-boot-espressobin.inc

LICENSE = "GPLv2+"
LIC_FILES_CHKSUM = "file://README;md5=8ff0837b355cf37b6b956f316d010d0c"

FILESEXTRAPATHS_prepend := "${THISDIR}/patches:"
FILESEXTRAPATHS_prepend_espressobin-v7 := "${THISDIR}/patches-v7:"

SRCREV = "${AUTOREV}"
SRCBRANCH = "u-boot-2018.03-armada-18.12"

SRC_URI_append = "\
    git://github.com/MarvellEmbeddedProcessors/u-boot-marvell.git;protocol=https;branch=${SRCBRANCH} \
    file://0001-espressobin-Add-CONFIG_DEFAULT_DEVICE_TREE-to-defcon.patch \
    file://0005-fw_env_main.c-Fix-incorrect-size-for-malloc-ed-strin.patch \
"

# TODO
#SRC_URI_append_espressobin-v7 = "\
#    file://0001-git-add-some-temporary-files-into-git-ignore-list.patch \
#    file://0002-mtd-add-issi-is25wp032d-spi-flash-support.patch \
#    file://0003-mtd-add-gigadevice-gd25lq32d-spi-flash-support.patch \
#"

S = "${WORKDIR}/git"
