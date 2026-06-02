def serve(track: int, curr_seektime: int) -> None:
    print(f'=> served track {track} | current seektime: {curr_seektime}')


def c_scan(num_processes: int, num_tracks: int, orig_pos: int, req_set: set) -> None:
    seektime = 0
    curr_pos = orig_pos
    for i in range(orig_pos, num_tracks + 1):
        print(f'head at track {i}')
        if i in req_set:
            seektime += abs(curr_pos - i)
            serve(i, seektime)
            curr_pos = i
    
    seektime += abs(num_tracks - curr_pos) # last requst position to end of disk
    seektime += num_tracks - 1 # jumping back to the beginning
    
    curr_pos = 1
    for i in range(1, orig_pos):
        print(f'head at track {i}')
        if i in req_set:
            seektime += abs(curr_pos - i)
            serve(i, seektime)
            curr_pos = i
            
    print(f'total seektime (C-SCAN Algorithm): {seektime}')
    
    
c_scan(7, 20, 6, {20, 7, 9, 3, 6, 18, 15})