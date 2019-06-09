| 参数              | 参数意义                                               |
| ----------------- | ------------------------------------------------------ |
| anno              | 匿名拦截器，不需要授权、登录就可以访问                             |
| authc             | 需要登录授权才能访问。基于表单的拦截器                                   |
| authcBasic        | Basic HTTP 身份验证拦截器                              |
| logout            | 退出拦截器。如果推出成功，会redirect到设置的/url       |
| user              | 用户拦截器。登陆后，第二次没登陆但是有记住我都可以访问 |
| noSessionCreation | 不创建会话连接器，调用 subject.getSession(false)不会有什么问题，但是如果 subject.getSession(true)将抛出 DisabledSessionException异常；                                       |
| perms             | 权限拦截器，验证用户有没有拥有所有的权限                                             |
| port              | 端口拦截器                                             |
| rest              | rest风格拦截器 ，自动根据请求方法构建权限字符串                                        |
| roles             | 角色拦截器，验证用户是否拥有所有的角色                                             |
| ssl               | ssl拦截器，通过https协议才能通过                       |
|                   |                                                        |
