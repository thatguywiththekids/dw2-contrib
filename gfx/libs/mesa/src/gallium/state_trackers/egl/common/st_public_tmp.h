ST_PUBLIC(st_create_context,              struct st_context *,       struct pipe_context *pipe, const __GLcontextModes *visual, struct st_context *share)
ST_PUBLIC(st_destroy_context,             void,                      struct st_context *st)
ST_PUBLIC(st_copy_context_state,          void,                      struct st_context *dst, struct st_context *src, uint mask)
ST_PUBLIC(st_create_framebuffer,          struct st_framebuffer *,   const __GLcontextModes *visual, enum pipe_format colorFormat, enum pipe_format depthFormat, enum pipe_format stencilFormat, uint width, uint height, void *privateData)
ST_PUBLIC(st_resize_framebuffer,          void,                      struct st_framebuffer *stfb, uint width, uint height)
ST_PUBLIC(st_set_framebuffer_surface,     void,                      struct st_framebuffer *stfb, uint surfIndex, struct pipe_surface *surf)
ST_PUBLIC(st_get_framebuffer_dimensions,  void,                      struct st_framebuffer *stfb, uint *width, uint *height)
ST_PUBLIC(st_get_framebuffer_surface,     int,                       struct st_framebuffer *stfb, uint surfIndex, struct pipe_surface **surface)
ST_PUBLIC(st_get_framebuffer_texture,     int,                       struct st_framebuffer *stfb, uint surfIndex, struct pipe_texture **texture)
ST_PUBLIC(st_framebuffer_private,         void *,                    struct st_framebuffer *stfb)
ST_PUBLIC(st_unreference_framebuffer,     void,                      struct st_framebuffer *stfb)
ST_PUBLIC(st_make_current,                GLboolean,                 struct st_context *st, struct st_framebuffer *draw, struct st_framebuffer *read)
ST_PUBLIC(st_get_current,                 struct st_context *,       void)
ST_PUBLIC(st_flush,                       void,                      struct st_context *st, uint pipeFlushFlags, struct pipe_fence_handle **fence)
ST_PUBLIC(st_finish,                      void,                      struct st_context *st)
ST_PUBLIC(st_notify_swapbuffers,          void,                      struct st_framebuffer *stfb)
ST_PUBLIC(st_bind_texture_surface,        int,                       struct pipe_surface *ps, int target, int level, enum pipe_format format)
ST_PUBLIC(st_unbind_texture_surface,      int,                       struct pipe_surface *ps, int target, int level)
ST_PUBLIC(st_get_proc_address,            st_proc,                   const char *procname)
#undef ST_PUBLIC