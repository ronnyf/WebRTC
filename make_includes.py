#!/usr/local/bin/python3

import os
from pathlib import Path

src_path = '.'
inc_path = 'rtc_core_hdrs'
subdirs = ['api', 'audio', 'call', 'common_audio', 'common_video', 'generated', 'logging', 'media', 'modules', 'net', 'p2p', 'pc', 'rtc_base', 'rtc_tools', 'stats', 'system_wrappers', 'test', 'video', 'sdk/objc/native/src/audio', 'sdk/objc/components/audio']

if not os.path.exists(inc_path):
    print(f"destination does not exist at: '{os.getcwd()}'")
    os.makedirs(inc_path)

def filtered(name):
    return name.endswith('.h') or name.endswith('.inc') or name.endswith('hpp')

for subdir in subdirs:
    for dirpath, dirnames, filenames in os.walk(subdir):
        header_files = list(filter(lambda filename: filtered(filename), filenames))

        # dirpath exists in 'inc_dir'?
        inc_dir = os.path.join(inc_path, dirpath)
        if not os.path.exists(inc_dir):
            os.makedirs(inc_dir)

        for file_name in header_files:
            file_path = os.path.join(dirpath, file_name)
            symlink_path = os.path.relpath(file_path, inc_dir)
            try:
                os.symlink(symlink_path, os.path.join(inc_path, file_path))
            except FileExistsError:
                continue
            except OSError as err:
                print(f"error: {err}")
