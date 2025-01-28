_ = input()
pattern = input().split("*")
text = input()
if len(pattern) == 1:
    print("YES" if pattern[0] == text else "NO")
else:
    starts_with = text.startswith(pattern[0])
    ends_with = text.endswith(pattern[1])
    no_overlap = len(text) >= len(pattern[0]) + len(pattern[1])
    if starts_with and ends_with and no_overlap:
        print("YES")
    else:
        print("NO")

