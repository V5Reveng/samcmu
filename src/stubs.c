#include <errno.h>
#include <stddef.h>
#include <sys/stat.h>
#include <sys/times.h>
#include <unistd.h>

#include "api.h"

#undef errno
extern int errno;

void __attribute__((noreturn)) _exit(int code) {
	(void)code;
	v5_exit();
}

int _close(int file) {
	(void)file;
	return -1;
}

int _execve(char const* name, char* const* argv, char* const* env) {
	(void)name;
	(void)argv;
	(void)env;
	errno = ENOSYS;
	return -1;
}

int _fcntl(int fd, int flag, int arg) {
	(void)fd;
	(void)flag;
	(void)arg;
	errno = ENOSYS;
	return -1;
}

int _fork(void) {
	errno = ENOSYS;
	return -1;
}

int _fstat(int file, struct stat* st) {
	(void)file;
	(void)st;
	errno = EBADF;
	return -1;
}

int getentropy(void* buffer, size_t length) {
	(void)buffer;
	(void)length;
	errno = ENOSYS;
	return -1;
}

int _getpid(void) {
	return 1;
}

int _gettimeofday(struct timeval* restrict tp, void* restrict tzp) {
	(void)tzp;
	tp->tv_sec = 0;
	tp->tv_usec = 0;
	return 0;
}

int _isatty(int file) {
	(void)file;
	errno = EBADF;
	return -1;
}

int _kill(int pid, int sig) {
	(void)pid;
	(void)sig;
	errno = EINVAL;
	return -1;
}

int _link(char const* old, char const* new) {
	(void)old;
	(void)new;
	errno = ENOSYS;
	return -1;
}

off_t _lseek(int file, off_t offset, int whence) {
	(void)file;
	(void)offset;
	(void)whence;
	errno = EBADF;
	return -1;
}

int _mkdir(char const* path, mode_t mode) {
	(void)path;
	(void)mode;
	errno = ENOSYS;
	return -1;
}

int _open(char const* name, int flags, int mode) {
	(void)name;
	(void)flags;
	(void)mode;
	return -1;
}

ssize_t _read(int file, void* ptr, size_t len) {
	(void)file;
	(void)ptr;
	(void)len;
	// TODO read from user serial port
	errno = EBADF;
	return -1;
}

void* _sbrk(intptr_t amount) {
	extern char __heap_start[];
	extern char __heap_end[];
	static void* current_end = __heap_start;

	if (current_end + amount >= (void*)__heap_end) {
		errno = ENOMEM;
		return (void*)-1;
	} else {
		void* ret = current_end;
		current_end += amount;
		return ret;
	}
}

int sigprocmask(int how, sigset_t const* set, sigset_t* old) {
	(void)how;
	(void)set;
	(void)old;
	return -1;
}

int _stat(char const* file, struct stat* st) {
	(void)file;
	(void)st;
	errno = ENOENT;
	return -1;
}

clock_t _times(struct tms* ret) {
	(void)ret;
	// TODO get execution time
	return -1;
}

int _unlink(char const* name) {
	(void)name;
	errno = ENOENT;
	return -1;
}

int _wait(int* status) {
	(void)status;
	errno = ECHILD;
	return -1;
}

ssize_t _write(int file, void const* data, size_t len) {
	(void)file;
	(void)data;
	(void)len;
	// TODO write to user serial port
	errno = EBADF;
	return -1;
}
