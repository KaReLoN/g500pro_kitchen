Unpack script usage:
Usage: unpack-MT65xx.pl <infile> [COMMAND ...]
  Unpacks boot, recovery or logo image

Optional COMMANDs are:

  -kernel_only
    Extract kernel only from boot or recovery image

  -ramdisk_only
    Extract ramdisk only from boot or recovery image

  -force_logo_res <width> <height>
    Forces logo image file to be unpacked by specifying image resolution,
    which must be entered in pixels
     (only useful when no zlib compressed images are found)

	 
	 
	 
Repack script usage:
Usage: repack-MT65xx.pl COMMAND [...]

COMMANDs are:

  -boot <kernel> <ramdisk-directory> <outfile>
    Repacks boot image

  -recovery <kernel> <ramdisk-directory> <outfile>
    Repacks recovery image

  -logo [--no_compression] <logo-directory> <outfile>
    Repacks logo image