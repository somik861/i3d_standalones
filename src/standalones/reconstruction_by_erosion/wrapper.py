def reconstruction_by_erosion(img: np.ndarray, marker: np.ndarray) -> np.ndarray:
    io.imsave('__marker.tif', marker)
    rv = _call('reconstruction_by_erosion', img, '__marker.tif')
    os.remove('__marker.tif')
    return rv
