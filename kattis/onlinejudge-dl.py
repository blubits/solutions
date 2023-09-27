import os
import requests
import zipfile
import argparse

def download_problem(problem_id):
    url = f"https://onlinejudge.org/external/{problem_id[0]}/{problem_id}/sample.zip"
    r = requests.get(url)
    with open(f"{problem_id}.zip", "wb") as f:
        f.write(r.content)

    with zipfile.ZipFile(f"{problem_id}.zip", "r") as zip_ref:
        zip_ref.extractall(f"{problem_id}")

    os.remove(f"{problem_id}.zip")

    with open(f"{problem_id}/{problem_id}.cpp", "w") as f:
        f.write("#include<bits/stdc++.h>\nusing namespace std;\n\nint main() {\n\n}")
    
    os.system(f"code {problem_id}/{problem_id}.cpp")

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description='Download sample test cases from Online Judge and create a file called problem_id.cpp')
    parser.add_argument('problem', metavar='N', type=str, help='Problem ID')
    args = parser.parse_args()
    
    download_problem(args.problem)