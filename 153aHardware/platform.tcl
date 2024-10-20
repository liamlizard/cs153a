# 
# Usage: To re-create this platform project launch xsct with below options.
# xsct /home/parallels/workspace/153aHardware/platform.tcl
# 
# OR launch xsct and run below command.
# source /home/parallels/workspace/153aHardware/platform.tcl
# 
# To create the platform in a different location, modify the -out option of "platform create" command.
# -out option specifies the output directory of the platform project.

platform create -name {153aHardware}\
-hw {/home/parallels/Downloads/design_1_wrapper.xsa}\
-proc {microblaze_0} -os {standalone} -out {/home/parallels/workspace}

platform write
platform generate -domains 
platform active {153aHardware}
bsp reload
bsp setdriver -ip sevenSeg_0 -driver generic -ver 3.0 3.1
bsp write
bsp reload
catch {bsp regenerate}
bsp write
platform generate
catch {platform remove hardwareSetup}
platform active {153aHardware}
bsp reload
bsp write
platform generate
platform generate
