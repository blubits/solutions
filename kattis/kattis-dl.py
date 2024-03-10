import os
import requests
#!/usr/bin/python
import zipfile
import argparse

def download_problem(problem_id):
    url = f"https://open.kattis.com/problems/{problem_id}/file/statement/samples.zip"
    r = requests.get(url)
    with open(f"{problem_id}.zip", "wb") as f:
        f.write(r.content)

    with zipfile.ZipFile(f"{problem_id}.zip", "r") as zip_ref:
        zip_ref.extractall(f"{problem_id}")

    os.remove(f"{problem_id}.zip")

    with open(f"{problem_id}/{problem_id}.cpp", "w") as f:
        f.write("")
    
    os.system(f"code {problem_id}/{problem_id}.cpp")

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description='Download sample test cases from Kattis and create a file called problem_id.cpp')
    parser.add_argument('problems', metavar='id', type=str, help='Problem ID', nargs="+")
    args = parser.parse_args()
    for problem in args.problems:
        download_problem(problem)