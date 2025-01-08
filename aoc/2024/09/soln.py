FILENAME = "input"

def parse(filename):
    with open(filename) as f:
        return list(map(int, list(f.readline().strip())))
    
def solve(data):
    files = [data[i] for i in range(len(data)) if i % 2 == 0]
    free = False
    file_id = 0
    file_id_back = len(files) - 1
    block_no = 0
    ans = 0
    for part in data:
        if not free:
            while files[file_id] != 0:
                ans += block_no * file_id
                files[file_id] -= 1
                block_no += 1
            free = True
            file_id += 1
            if files[file_id] == 0:
                break
        else:
            curr_free = part
            while curr_free:
                ans += block_no * file_id_back
                files[file_id_back] -= 1
                if files[file_id_back] == 0: 
                    file_id_back -= 1
                    if files[file_id_back] == 0: break
                block_no += 1 
                curr_free -= 1
            free = False
    return ans


def solve2(data):
    files = dict()
    frees = []
    start = 0
    free = False
    file_id = 0
    for part in data:
        if not free:
            files[file_id] = (start, start + part - 1)
            file_id += 1
            free = True
        else:
            if start <= start + part - 1:
                frees.append((start, start + part - 1))
            free = False
            
        start += part
    # For each file in descending order of ID:
    for file_id in range(len(files) - 1, -1, -1):
        # Do first-fit allocation.
        curr_loc_i, curr_loc_j = files[file_id]
        file_space = curr_loc_j - curr_loc_i + 1
        for idx in range(len(frees)):
            i, j = frees[idx]
            # Always move a file left.
            # If the free space is to the right of a file, do not move.
            if curr_loc_j < i: break
            # Move here if free space is enough for the file.
            free_space = j - i + 1
            # Case 1: Free space is exactly equal to the file space.
            if free_space == file_space:
                # That means the file just takes up the free space.
                frees.remove((i, j))
                files[file_id] = (i, j)
                break
            # Case 2: Free space is more than the file space.
            if free_space > file_space:
                # The file takes up a portion of the free space...
                files[file_id] = (i, i + file_space - 1)
                # while the free space shortens.
                idx = frees.index((i, j))
                frees[idx] = (i + file_space, j)
                break
    ans = 0
    for file, space in files.items():
        for block_idx in range(space[0], space[1] + 1):
            ans += file * block_idx
    return ans

data = parse(FILENAME)
print(solve(data))
print(solve2(data))