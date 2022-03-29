# Dependencies
This folder will hold external projects that we might need to depend on.

## Ghidra
This is the c++ source code stripped out of
[ghidra](https://github.com/NationalSecurityAgency/ghidra). We include this as a
convenience to the user so that cloning the entire ghidra repo (c++ AND Java code) is
unnecessary. NOTE that this does not imply the code here is old/stale. The update script
`update_ghidra_src.py` may be used to pull in the latest c++ code from the ghidra
repository.
