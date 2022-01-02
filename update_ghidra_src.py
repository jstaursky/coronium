#!/usr/bin/env python3

import requests
import os

src_names = os.listdir(os.path.join(os.getcwd(), "src"))
hdr_names = os.listdir(os.path.join(os.getcwd(), "include"))

github_api_url = 'https://api.github.com/repos/NationalSecurityAgency/ghidra/contents/Ghidra/Features/Decompiler/src/decompile/cpp'
req = requests.get(github_api_url)
ghidra_json = req.json()

# Download all files in the src/decompile/cpp subdirectory github.com/NationalSecurityAgency/ghidra
for el in ghidra_json:
    if src_names.count(el["name"]) > 0:
        print("updating file " + el["name"])
        fcontent = requests.get(el["download_url"])
        fpath = os.path.join(os.getcwd(), "src", el["name"])
        file = open(fpath, 'w')
        file.write(fcontent.text)

    if hdr_names.count(el["name"]) > 0:
        print("updating file " + el["name"])
        fcontent = requests.get(el["download_url"])
        fpath = os.path.join(os.getcwd(), "include", el["name"])
        file = open(fpath, 'w')
        file.write(fcontent.text)
