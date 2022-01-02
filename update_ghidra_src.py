#!/usr/bin/env python3

import requests
import os

src_names = os.listdir(os.path.join(os.getcwd(), "src"))
hdr_names = os.listdir(os.path.join(os.getcwd(), "include/coronium"))
parse_names = os.listdir(os.path.join(os.getcwd(), "parse"))


github_api_url = 'https://api.github.com/repos/NationalSecurityAgency/ghidra/contents/Ghidra/Features/Decompiler/src/decompile/cpp'
req = requests.get(github_api_url)
ghidra_json = req.json()

# Download files in the Ghidra/Features/Decompiler/src/decompile/cpp subdirectory from github.com/NationalSecurityAgency/ghidra
for el in ghidra_json:
    if el["name"] in src_names:
        print("updating file " + el["name"])
        fcontent = requests.get(el["download_url"])
        fpath = os.path.join(os.getcwd(), "src", el["name"])
        file = open(fpath, 'w')
        file.write(fcontent.text)

    if el["name"] in hdr_names:
        print("updating file " + el["name"])
        fcontent = requests.get(el["download_url"])
        fpath = os.path.join(os.getcwd(), "include/coronium", el["name"])
        file = open(fpath, 'w')
        file.write(fcontent.text)

    if el["name"] in parse_names:
        print("updating file " + el["name"])
        fcontent = requests.get(el["download_url"])
        fpath = os.path.join(os.getcwd(), "parse", el["name"])
        file = open(fpath, 'w')
        file.write(fcontent.text)
