#include "shell.h

/**
 * input_buf - buffers chained commands
 * @info: parameter struct
 * @buf: address of buffer
 * @len: address of len var
 *
 * Return: bytes read
 */"
ssize_t get_input(info_t *info)
{
    static char *buf = NULL;
    static size_t i = 0, j = 0, len = 0;
    ssize_t r = 0;
    char **buf_p = &(info->arg), *p;

    _putchar(BUF_FLUSH);
    r = input_buf(info, &buf, &len);

    if (r == -1) 
    	    return -1;

    if (len) 
    {
        j = i;
        p = buf + i;

        check_chain(info, buf, &j, i, len);
        while (j < len)
        {
            if (is_chain(info, buf, &j))
                break;
            j++;
        }

        i = j + 1;
        if (i >= len)
        {
            i = len = 0;
            info->cmd_buf_type = CMD_NORMAL;
        }

        *buf_p = p;
        return _strlen(p);
    }

    *buf_p = buf;
    return r;
}
