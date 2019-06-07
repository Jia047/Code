Spring Security提供了很多过滤器，它们拦截Servlet请求，并将这些请求转交给认证处理过滤器和访问角色过滤器进行处理，并强制安全性。

[toc]

### SecurityContextPersistentenceFilter
1. 第一个起作用的过滤器。在其他过滤器之前，检查该用户的会话是否已经在Spring Security的上下文的 SpringSecurityContext，如果存在的话，就将SpringSecurityContext放入SpringContextHolder中给SpringSecurity的其他部分使用；如果不存在，就创建一个放入SpringContextHolder中。
2. 在所有过滤器执行完毕后清空SpringContextHolder的内容，因为SpringContextHolder是基于ThreadLocal的，如果操作完没有清空ThreadLocal，会受到线程池机制的影响。

### LogoutFilter
1. 只处理注销请求，在收到用户的注销请求后，销毁用户的session，清空SpringContextHolder，重定向到注销成功的页面，也可以与rememberme之类的功能机制相结合，在注销时清空用户的cookie

### AbstractAuthenticationProcessingFileter
1. 处理Form登录的过滤器，与form有关的操作都在此进行。
2. 此过滤器的基本操作时通过用户名及密码判断用户是否有效
    1. 如果有效，就跳到登录成功页面
    2. 如果无效，就跳到登录失败页面

### DefaultLoginPageGeneratingFilter
1. 用来生成一个默认的登录页面。实际不会用到它。

### BasicAuthenticationFilter
1. 主要用于Basic验证，功能与AbstractAuthenticationProcessingFileter一样，只不过验证的方式不同。

### SecurityContextHolderAwareRequestFilter
1. 用来包装用户的请求，目的是在原来的请求的基础之上对后续程序提供额外的数据

### RememberMeAuthenticationFilter
1. 实现记住密码的功能，当用户Cookie中存在RememberMe标识时，它会根据标记自动识验用户登录，并创建SecurityContext，授予对应的Spring Security的RememberMe功能是基于Cookie实现的，当用户登录的时候使用RememerMe是，系统就会在登录成功后，将为用户生成一个唯一的标志，并将这个标志保存到
保存进Cookie中

### AnonymousAuthenticationFilter
1. 当用户未登录时，默认为用户分配匿名用户的权限

### ExceptionTranslatationFilter
1. 为了处理FilterSercurityInterceptor中抛出的异常，然后将请求重定向到对应的页面或返回对应的响应错误代码

### SessionManagementFilter
1. 主要是为了防御会话伪造攻击，这个主要是在用户登陆之后销毁用户的当前session并重新生成一个session

### FilterSecurityInterceptor
1. 用户的权限控制都包含在这个过滤器上
2. 如果用户尚未登录，那么抛出未认证的一场
3. 如果用户已经登录，但是没有访问当前资源的权限，就会抛出拒绝访问的异常
4. 如果用户已经登陆，并且有权限访问资源，那么放行。

### FilterChainProxy
1. FilterChainProxy会按照顺序来调用一组Filter，是这些Filter既能完成验证授权的本职工作又能想用Spring IOC带来的便利性。
