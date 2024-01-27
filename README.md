## Transmitter

Transmitter code can be found in `src\transmitter\transmitter.cpp`. Transmitter transmits at 915Mhz RF with bandwidth 125Khz, a coding rate of 1, and power at 22dBm.

## Receiver

Receiver code can be found in `src\receiver\receiver.cpp`. Receiver listens to 915Mhz RF.

## Development

This assumes that the user has already initialized PlatformIO and have Python and Pip installed on their development machine.

1. **Install `pre-commit` globally:**

Run:
```
pip install pre-commit
```

2. **Use `pre-commit`:**

Run:
```
PYTHON_PREFIX -m pre_commit run
```
