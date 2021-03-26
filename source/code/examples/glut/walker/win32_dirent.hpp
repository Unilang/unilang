
/* For Win32 that lacks Unix direct support. */

struct dirent
{ char d_name[MAX_PATH]; };

typedef struct 
{ WIN32_FIND_DATA  wfd;
  HANDLE hFind;
  struct dirent de;
} DIR;


DIR *opendir(char *pSpec)
{ DIR *pDir = malloc(sizeof(DIR));
  pDir->hFind = FindFirstFile(pSpec, &pDir->wfd);
  return pDir;
}

void closedir(DIR *pDir)
{ FindClose(pDir);
  free(pDir);
}

struct dirent *readdir(struct DIR *pDir)
{ if (pDir->hFind)
  { strcpy(pDir->de.d_name, pDir->wfd.cFileName);
    if (!FindNextFile(pDir->hFind, &pDir->wfd))
       pDir->hFind = NULL;
    return &pDir->de;
  }
  return NULL;
}

#define fclose(f)  { if (f!=NULL) fclose(f); }

