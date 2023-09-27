import webbrowser
import sys
import os

if len(sys.argv) == 1:
    problem_id = os.path.basename(os.getcwd())
else:
    problem_id = sys.argv[1]
url = f"https://open.kattis.com/problems/{problem_id}"
webbrowser.open(url)