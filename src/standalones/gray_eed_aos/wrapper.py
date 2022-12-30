def gray_eed_aos(img: np.ndarray, sigma: float, lambda_: float, tau: float, num_iter: int) -> np.ndarray:
    return _call('gray_eed_aos', img, sigma, lambda_, tau, num_iter)
