首先我得承认，这个问题我以前没有遇到过。刚看到这个问题时，脑子里并没有什么思路。我能想到的切入点只有**反向代理服务器 nginx** 和 **后端服务器**，就是tomcat，我想应该是从这个两个点切入。后来我用google搜索了一下，发现这个问题很多人都遇到过并且已经有了解决方案。

我进行一番搜索之后，对该问题发生的原因以及解决方法有了些了解。
首先，客户端发送的请求并非直接到达tomcat服务器，而是经过了nginx转发到后端服务器，那么有一个原因是**在转发过程中，scheme发生了变化**。其次，也**有可能是tomcat服务器对于HTTPS请求没有识别能力**。

网上的解决办法一般是两步。

先在Nginx的配置文件中在普通HTTP配置的基础上加上转发选项：
```
proxy_set_header X-Forwarded-Proto $scheme;
```
然后是在tomcat的server.xml文件中添加一个Valve（RemoteIpValve），不过这里是springboot，并没有server.xml，但是可以在Springboot 的 application.properties文件中添加配置，效果应该是一样的
```java
server.tomcat.remote-ip-header=X-FORWARDED-FOR
server.tomcat.protocol-header=X-Forwarded-Proto
server.tomcat.port-header=X-Forwarded-Port
server.use-forward-headers=true
```
