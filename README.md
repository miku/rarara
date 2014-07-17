rarara
======

Prime [buffer cache](http://www.tldp.org/LDP/sag/html/buffer-cache.html) for a file via [readahead](http://man7.org/linux/man-pages/man2/readahead.2.html) from the command line (linux only).

Usage
-----

    $ rarara FILENAME [OFFSET [COUNT]]

Defaults: `OFFSET=0, COUNT=1073741824`.

See also
--------

* http://unix.stackexchange.com/q/145034/376
* http://www.reddit.com/r/linux/comments/2axv21/tiny_tool_to_prime_buffer_cache_for_a_file/
