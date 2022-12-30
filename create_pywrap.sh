#! /bin/bash

echo "import numpy as np
import subprocess
from skimage import io
import os


def _call(name: str, img: np.ndarray, *args) -> np.ndarray:
    str_args = tuple(str(arg) for arg in args)
    INP_NAME = '__inp.tif'
    OUT_NAME = '__out.tif'
    io.imsave(INP_NAME, img, check_contrast=False, compression='zlib')
    subprocess.run([os.path.join(os.path.dirname(os.path.realpath(__file__)), 'bin', name), INP_NAME, OUT_NAME, *str_args], check=True)
    img = io.imread(OUT_NAME)
    os.remove(INP_NAME)
    os.remove(OUT_NAME)
    return img
    
" > $1 

cat src/standalones/*/wrapper.py >> $1
