def gray_ced_aos(img: np.ndarray, sigma: float, rho: float, tau: float, num_iter: int) -> np.ndarray:
    return _call('gray_ced_aos', img, sigma, rho, tau, num_iter)
