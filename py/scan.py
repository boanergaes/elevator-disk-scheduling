def serve(track: int, curr_seektime: int) -> None:
    print(f'=> served track {track} | current seektime: {curr_seektime}')


def scan(num_processes: int, num_tracks: int, orig_pos: int, req_set: set) -> None:
    least_req = min(req_set)
    seektime = 0
    curr_pos = orig_pos
    for i in range(orig_pos, num_tracks + 1):
        # print(f'head at track {i}')
        if i in req_set:
            seektime += abs(curr_pos - i)
            serve(i, seektime)
            curr_pos = i
            req_set.remove(i)
    
    # curr_pos = 1
    for i in range(num_tracks - 1, least_req - 1, -1):
        # print(f'head at track {i}')
        if i in req_set:
            seektime += abs(curr_pos - i)
            serve(i, seektime)
            curr_pos = i
            req_set.remove(i)
            
    print(f'total seektime (SCAN Algorithm): {seektime}')
    
    
scan(7, 20, 6, {20, 7, 9, 3, 6, 18, 15})