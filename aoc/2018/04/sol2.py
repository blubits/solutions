with open("input.txt") as input_file:
    logs = [line.rstrip('\n') for line in input_file.readlines()]
    logs.sort()
    current_guard = 0
    sleep_time = 0
    awake_time = 0
    sleep_logs = {}
    for log in logs:
        _, time, *message = log.split()
        _, minute = [int(x) for x in time.rstrip("]").split(":")]
        if message[0] == "Guard":
            current_guard = int(message[1].lstrip("#"))
            if current_guard not in sleep_logs:
                sleep_logs[current_guard] = [0] * 60
        elif message[0] == "falls":
            sleep_time = minute
        elif message[0] == "wakes":
            awake_time = minute
            for m in range(sleep_time, awake_time):
                sleep_logs[current_guard][m] += 1
    m_sleep = 0
    m_sleep_gid = 0
    m_max_min = 0
    m_max_idx = 0
    for guard in sleep_logs:
        for idx, sleep in enumerate(sleep_logs[guard]):
            if sleep > m_max_min:
                m_max_min = sleep
                m_max_idx = idx
                m_sleep_gid = guard
        print(m_sleep_gid, m_max_idx)
    print(m_sleep_gid * m_max_idx)
