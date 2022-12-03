def reconstruction_by_dilation(img: np.ndarray, marker: np.ndarray) -> np.ndarray:
    assert np.all(marker <= img)
    io.imsave('__marker.tif', marker, check_contrast=False)
    rv = _call('reconstruction_by_dilation', img, '__marker.tif')
    os.remove('__marker.tif')
    return rv
