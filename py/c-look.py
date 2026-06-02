def serve(track: int, curr_seektime: int) -> None:
    print(f'=> served track {track} | current seektime: {curr_seektime}')


def c_look(num_processes: int, num_tracks: int, orig_pos: int, req_list: list) -> None:
    req_list.sort()
    
    before_orig: list = []
    after_orig: list = []
    for r in req_list:
        if r >= orig_pos:
            after_orig.append(r)
        else:
            before_orig.append(r)
            
    seektime: int = 0  
    
    curr_pos = orig_pos
    for req in after_orig:
        seektime += abs(curr_pos - req)
        serve(req, seektime)
        curr_pos = req
        
    # jump back to the lowest requested track and start looking
    for req in before_orig:
        seektime += abs(curr_pos - req)
        serve(req, seektime)
        curr_pos = req
        
    print(f'total seektime (C-LOOK Algorithm): {seektime}')
            
c_look(7, 20, 6, [20, 5, 7, 9, 3, 6, 18, 15])