import requests
res = requests.get("https://cdn.jsdelivr.net/gh/duongnguyen291/DSA@main/labs/week15/ex1.cpp")
print(res.text)