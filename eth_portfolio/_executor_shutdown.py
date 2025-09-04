import atexit
import signal

def register_executor_shutdown(executors, name="executor"):
    """
    Registers atexit and chainable signal handlers to shutdown all executors in the given iterable.
    """
    def shutdown_all(*args):
        for executor in list(executors):
            try:
                executor.shutdown(wait=False)
            except Exception:
                pass

    atexit.register(shutdown_all)

    def make_chainable_signal_handler(signalnum):
        prev_handler = signal.getsignal(signalnum)
        def handler(signum, frame):
            shutdown_all()
            if callable(prev_handler) and prev_handler not in (signal.SIG_DFL, signal.SIG_IGN):
                prev_handler(signum, frame)
        signal.signal(signalnum, handler)

    make_chainable_signal_handler(signal.SIGINT)
    make_chainable_signal_handler(signal.SIGTERM)
