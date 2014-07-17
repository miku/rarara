rarara
======

Prime [buffer cache](http://www.tldp.org/LDP/sag/html/buffer-cache.html) for a file via [readahead](http://man7.org/linux/man-pages/man2/readahead.2.html) from the command line (linux only).

> readahead() initiates readahead on a file so that subsequent reads
  from that file will be satisfied from the cache, and not block on
  disk I/O (assuming the readahead was initiated early enough and that
  other activity on the system did not in the meantime flush pages from
  the cache).


Usage
-----

    $ rarara FILENAME [OFFSET [COUNT]]

Try to cache the whole file starting at the beginning by default.

Alternatives
------------

[dd](http://en.wikipedia.org/wiki/Dd_%28Unix%29), which is [POSIX](http://pubs.opengroup.org/onlinepubs/9699919799/utilities/dd.html). Example 2.5G file:

    $ time rarara big.file 0 2459650481
    real    0m13.803s

    $ time dd if=big.file of=/dev/null bs=4096 count=600501 skip=0
    real    0m14.394s

7.4 GB file:

    $ time dd if=bigger.file of=/dev/null bs=64k
    113123+1 records in
    113123+1 records out
    7413691873 bytes (7.4 GB) copied, 43.7198 s, 170 MB/s

    real	0m43.778s
    user	0m0.028s
    sys	  0m3.672s

    $ time rarara bigger.file
    readahead [0:7413691873]

    real	0m23.753s
    user	0m0.004s
    sys	  0m0.464s


See also
--------

* http://unix.stackexchange.com/q/145034/376
* http://www.reddit.com/r/linux/comments/2axv21/tiny_tool_to_prime_buffer_cache_for_a_file/
