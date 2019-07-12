### 主要组件
- 安全拦截器
- 认证管理器
- 访问决策管理器
- 运行身份管理器

### 身份认证模式
- Basic
    - 无状态
    - 传输安全性不足
- Digest
    - 解决Basic的安全问题
    - 认证报文可以被拦截
- X.509
    - 需要证书
- LDAP（light database access protol)
- Form

### Spring Security 权限拦截
- SecutiryContextPersistenceFilterx'x
- LogoutFilter：处理注销
- AbstractAuthenticationProcessingFileter
- DefaultLoginPageGeneratingFilter
- BasicAuthenticationFilter
- SecurityContextHolderAwareRequestFilter- RememberMeAuthenticationFilter
- AnonymousAuthenticationFilter
- ExceptionTranslatationFilter
- SessionManagementFilter
- FilterSecurityInterceptor
- FilterChainiProxy 
