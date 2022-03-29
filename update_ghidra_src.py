#!/usr/bin/env python3

import argparse
import requests
import os
import pathlib

parser = argparse.ArgumentParser(description='Script for updating ghidra source files and (optionally) cpu definition files.')
parser.add_argument("--cpus", help='Update cpu definitions', action="store_true")
parser.add_argument("--token", help='authorization token (to increase github request limit)', default="")

args = parser.parse_args()

src_names = os.listdir(os.path.join(os.getcwd(), "dependencies/ghidra/src"))
hdr_names = os.listdir(os.path.join(os.getcwd(), "dependencies/ghidra/include"))
parse_names = os.listdir(os.path.join(os.getcwd(), "dependencies/ghidra/parse"))

if args.token:
    request = lambda x: requests.get(x, headers={"Authorization": "token " + args.token})
else:
    request = lambda x: requests.get(x)


# Default to only updating the c++ source files and only update cpus when the --cpus option is specified.
if not args.cpus:
    # Download files in the Ghidra/Features/Decompiler/src/decompile/cpp subdirectory from github.com/NationalSecurityAgency/ghidra
    github_api_url = 'https://api.github.com/repos/NationalSecurityAgency/ghidra/contents/Ghidra/Features/Decompiler/src/decompile/cpp'

    req = request(github_api_url)
    ghidra_json = req.json()

    for el in ghidra_json:
        if el["name"] in src_names:
            print("updating file " + el["name"])
            fcontent = request(el["download_url"])
            fpath = os.path.join(os.getcwd(), "dependencies/ghidra/src", el["name"])
            file = open(fpath, 'w')
            file.write(fcontent.text)

        if el["name"] in hdr_names:
            print("updating file " + el["name"])
            fcontent = request(el["download_url"])
            fpath = os.path.join(os.getcwd(), "dependencies/ghidra/include", el["name"])
            file = open(fpath, 'w')
            file.write(fcontent.text)

        if el["name"] in parse_names:
            print("updating file " + el["name"])
            fcontent = request(el["download_url"])
            fpath = os.path.join(os.getcwd(), "dependencies/ghidra/parse", el["name"])
            file = open(fpath, 'w')
            file.write(fcontent.text)


if args.cpus:
    github_cpu_api_url = 'https://api.github.com/repos/NationalSecurityAgency/ghidra/contents/Ghidra/Processors'

    cpu_req = request(github_cpu_api_url)
    cpu_json = cpu_req.json()

    def get_data(url):
        link = request(url)
        if (link.json()):
            json = link.json()
            for e in json:
                if e["download_url"] is None:
                    get_data(e["url"])
                else:
                    path = pathlib.Path(e["path"])
                    if path.suffix == ".java" or path.suffix == ".gradle":
                        continue
                    fpath = pathlib.Path(*path.parts[1:]).resolve()
                    file = pathlib.Path(fpath.as_posix().lower())
                    file.parent.mkdir(parents=True, exist_ok=True)
                    file.touch(exist_ok=True)
                    filelowercase = fpath.as_posix().lower()
                    print("updating file " + filelowercase)
                    fcontent = request(e["download_url"])
                    fh = open(filelowercase, 'w')
                    fh.write(fcontent.text)

    get_data(github_cpu_api_url)
