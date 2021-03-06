SUMMARY = "Linux Kernel for Globalscale Marvell ESPRESSObin"
DESCRIPTION = "Linux Kernel for Globalscale Marvell ESPRESSObin"
HOMEPAGE = "https://git.kernel.org/"

DEPENDS_append = " kern-tools-native xz-native bc-native"
DEPENDS_append_aarch64 = " libgcc"
KERNEL_CC_append_aarch64 = " ${TOOLCHAIN_OPTIONS}"
KERNEL_LD_append_aarch64 = " ${TOOLCHAIN_OPTIONS}"

inherit kernel

do_configure_prepend () {
    mkdir -p ${B}
    cp '${WORKDIR}/defconfig' '${B}/.config'
    merge_config.sh -m ${B}/.config ${@' '.join([s for s in src_patches(d, True) if s.endswith('.cfg')])}
}

FILESEXTRAPATHS_prepend := "${THISDIR}/configs:"

SRC_URI += "file://defconfig"
SRC_URI += "${@bb.utils.contains('TUNE_FEATURES', 'bigendian', 'file://bigendian.cfg',  '', d)}"

COMPATIBLE_MACHINE = "(espressobin-v5|espressobin-v7)"

# sd card is slow to probe
CMDLINE_append = " rootwait"

