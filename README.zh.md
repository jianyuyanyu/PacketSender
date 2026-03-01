# 简介

![Packet Sender Logo](screenshots/packetsender_banner.png)

### [https://packetsender.com](https://packetsender.com/)


*阅读其他语言版本：[English](README.md), [Español](README.es.md), [Deutsch](README.de.md), [Français](README.fr.md), [italiano](README.it.md), [简体中文](README.zh.md).*


[![Downloads](https://img.shields.io/github/downloads/dannagle/PacketSender/total.svg)](https://packetsender.com/download)

Packet Sender 是一款开源工具，可用于发送和接收 TCP、UDP 以及 SSL（加密 TCP）数据包，同时支持 HTTP/HTTPS 请求和面板生成。主分支正式支持 Windows、Mac 和桌面 Linux（基于 Qt）。其他平台可能会重新编译并重新分发 Packet Sender。Packet Sender 完全免费，采用 GPL v2 或更高版本许可，可用于商业和个人用途。如果您觉得这款应用有用，请考虑捐赠或赞助，以便开发工作得以持续。



# 目录
* [赞助商](#sponsors)
    * 访问 [IWL.com](https://www.iwl.com/)
    * 访问 [NagleCode.com](https://dannagle.com/)
    * 访问 [Eletiope.com](http://eletiope.com/)
    * 访问 [John Huntington](https://www.controlgeek.net/)
* [图形界面](#gui)
* [高强度流量生成器 (GUI)](#udptraffic)
* [网络](#network)
* [下载](#downloads)
* [iOS 移动应用](#ios)
* [支持](#support)
* [IPv4 子网计算器](#subnetcalculator)
* [Wake-On-LAN / Magic Packet](#wakeonlan)
* [Packet Sender Cloud](#cloud)
* [便携模式](#portable)
* [宏与智能响应](#smartresponses)
* [持久 TCP 和 SSL](#persistent)
* [HTTP/HTTPS 请求](#http)
* [面板生成器](#panelgen)
* [命令行界面](#cli)
* [高强度流量生成器 (CLI)](#cliintensetraffic)
* [编译 Packet Sender](#building)




<a id="sponsors"></a>
## 赞助商

Packet Sender 感谢以下赞助商。

[![IWL](screenshots/iwl_logo.png)](https://www.iwl.com/)
<br>IWL 是一家位于加州的计算机网络产品制造商。
<br><br><br>

[![NagleCode](screenshots/naglecode-logo400.png)](https://dannagle.com)
<br>NagleCode 是一家软件发行商和开发工作室。
<br><br><br>

[![Eletiope](screenshots/eletiope_logo400.png)](http://eletiope.com)
<br>Eletiope 为展览馆、博物馆和企业展厅提供照明、视听和沉浸式空间安装服务。
<br><br><br>

[John Huntington](https://www.controlgeek.net/)
<br>作家、顾问、教育家、音响工程师、获奖摄影师和风暴追逐者。
<br><br><br>

[想让您的名字/Logo 出现在这里吗？](https://github.com/sponsors/dannagle)



<a id="support"></a>
## 支持

* Twitter/X: [@NagleCode](https://x.com/NagleCode)
* 论坛位于：[GitHub Discussions](https://github.com/dannagle/PacketSender/discussions)。
* 邮箱：[Packet Sender 联系方式](https://packetsender.com/contact)
* 在 [LinkedIn](https://www.linkedin.com/in/dannagle/) 上与我联系

*注意：* 如果在 Windows 上遇到问题，请尝试（临时）禁用防火墙。

<a id="downloads"></a>
# 下载

## 桌面版下载
Packet Sender 的官方发布版可从 [PacketSender.com](https://packetsender.com/download) 下载。部分平台会重新分发 Packet Sender。

![Windows Logo](screenshots/winlogo150.png) ![Mac Logo](screenshots/maclogo150.png) ![Linux Logo](screenshots/Tux150.png)


<!-- 
Not sure when this will be back.

## Mobile Apps


### Android Mobile App
![Android Logo](screenshots/android_logo.png)

The Android version is located [on Google Play](https://play.google.com/store/apps/details?id=com.packetsender.compose) or [on Amazon Appstore](https://www.amazon.com/dp/B08RXM6KM2/)

[![Packet Sender Android](screenshots/packetsender_android_screenshot.png)](https://play.google.com/store/apps/details?id=com.packetsender.compose

-->



<a id="ios"></a>
## iOS 移动应用
Packet Sender for iOS 是完全原生的，只包含最低权限，不收集任何数据。这是一款尊重用户的软件。感谢您支持这项工作。

iOS 版本位于 [Apple App Store](https://apps.apple.com/app/id1558236648#?platform=iphone)

[![Packet Sender iOS](screenshots/packetsender-ios-traffic-log-ascii.png)](https://apps.apple.com/app/id1558236648#?platform=iphone)

<a id="gui"></a>
# 图形界面

Packet Sender 在所有桌面平台上的界面完全一致，仅主题会适配操作系统。

![Packet Sender screenshot](screenshots/ps_GUI.png)

1. 一个数据包包含名称、目标地址（域名会在发送前默认解析）、端口和关联数据。
2. 表格中列出已保存的数据包。您可以双击直接编辑表格中的字段。
3. 右下角显示 UDP、TCP 和 SSL 服务器状态及端口。点击即可激活或停用对应协议。Packet Sender 支持绑定任意数量的端口。
4. 还有一个 IP 切换按钮。点击可在 IPv4（默认）、IPv6 或自定义 IP 之间切换。

### 常规说明
* 重发值为 “0” 表示单次发送的数据包。
* 重发过程中会出现取消所有重发的按钮。
* 请检查您的防火墙。Windows 会积极阻止基于 TCP 的服务器。即使防火墙阻止，Packet Sender 仍可正常工作，但无法接收未请求的 TCP 数据包。
* 可以设置可选的响应。该响应对 TCP、UDP 和 SSL 通用。
* 发送 IPv6 时还需要指定 scope ID。
* Packet Sender 支持混合 ASCII 和 HEX 表示法：
    * 双击任意字段可打开多行编辑器
    * \XX 会转换为十六进制的 XX
    * \n、\r、\t 会分别转换为 0A、0D、09
    * HEX 数值以空格分隔
        * HEX 字段会自动识别常见分隔符（如逗号、冒号（Wireshark）、分号、“0x”等）并自动修正，具有很强的容错性。
        * 也支持连续的 HEX 流。如果字节数为奇数，Packet Sender 会自动在前方补零并修正。
    * 示例 ASCII：hello world\r
    * 示例 HEX：68 65 6c 6c 6f 20 77 6f 72 6c 64 0d
    * 您可以直接从流量日志保存数据包。系统会提示输入名称，并自动交换源地址和端口以方便使用。
    * 也可以直接将文件加载到 HEX 字段。HEX 字段支持发送最多 10,922 字节。通过命令行发送的理论上限为 200 MB。


## 快捷键 / 键盘快捷方式

顶部字段可使用 CTRL+1、CTRL+2 … CTRL+8（发送按钮）进行导航。在 Mac 上快捷键为 Command。

快捷键与对应字段如下：
* CTRL + 1 = 名称
* CTRL + 2 = ASCII
* CTRL + 3 = HEX
* CTRL + 4 = 地址
* CTRL + 5 = 端口
* CTRL + 6 = 重发延迟
* CTRL + 7 = 协议选择
* CTRL + 8 = 发送（执行）


部分说明：
* 字段始终与对应快捷键关联，与当前协议无关。
* 当导航到 TCP/UDP/SSL 选项时，可使用上下箭头或 t/u/s/h 字符进行选择。
* 如果您要使用热键自动化（如 [AutoHotKey](https://www.autohotkey.com/)），建议关闭“恢复上一个会话”。



<a id="network"></a>
# 网络功能

## 基本设置
默认情况下，Packet Sender 启动时会在随机端口上启用 UDP、TCP 和 SSL 服务器（显示在右下角按钮）。您可以使用逗号分隔的端口号绑定任意数量端口，例如 `0, 1000, 2000` 将绑定“随机”端口以及 1000、2000 端口。

![Basic Network Settings](screenshots/basic_network_settings.png)

UDP 按钮现在显示已绑定 3 个端口，其中 1 个是随机的。

![Bound UDP Example](screenshots/bound_udp_example.png)

另一项设置是对所有请求回复响应。您也可以让响应包含宏。有一个字段用于输入响应（或加载已保存的数据包）。


## 额外的 UDP/TCP/SSL 设置
默认情况下 Packet Sender 绑定到任意 IPv4 地址。在设置的该区域，您可以改为绑定任意 IPv6 地址或指定 IP 地址。

绑定到特定地址在有多张网卡时非常有用，可强制（如广播数据包）从指定网卡发出。

![Bound UDP Example](screenshots/additional_network_settings.png)

部分协议要求服务器在客户端发送前先发送数据（如许多 telnet 服务）。可通过“接收后再发送”启用此流程。

如果您的设备较慢（如处理器较弱的嵌入式服务器），建议启用“连接后延迟 500 ms”，让慢速服务器有时间启动处理程序。

## IPv4、IPv6、自定义 IP

Packet Sender 的内置服务器配置为同时支持 IPv4 或 IPv6，但不能同时支持两者。对于客户端，Packet Sender GUI 和 CLI 在发送时会自动无缝切换两种模式（IPv6 可能需要 scope ID）。点击右下角的 IPv4 / IPv6 切换按钮即可切换。

在设置中，您还可以强制 Packet Sender 的服务器绑定到自定义 IP 地址。这对拥有多网卡或复杂 IP 配置的系统非常有用。如果绑定的地址不存在，Packet Sender 会触发错误。

![IP Specific binding](screenshots/ip-specific-binding.png)


<a id="subnetcalculator"></a>
## IPv4 子网计算器

Packet Sender 内置子网计算器，位于“工具”菜单中。
![Packet Sender Subnet Calc](screenshots/packetsender_subnetcalc.PNG)

* 日志窗口（底部区域）会显示计算机上找到的非回环 IPv4 和 IPv6 地址。
* 左侧在 IP 字段输入 IPv4 地址。
* 左侧在子网字段输入 X.X.X.X 或 /XX 格式。
* 计算结果显示在右侧。
* 下方字段可快速检查某个 IPv4 是否属于您的某个子网。


<a id="wakeonlan"></a>
## Wake-On-LAN / Magic Packet

Wake-On-LAN（或 WOL）是一种协议，用于将计算机从睡眠状态唤醒。它通过发送包含基于目标 MAC 地址的特殊数据的广播包来触发。更多信息请参阅 [Wikipedia](https://en.wikipedia.org/wiki/Wake-on-LAN)。

Packet Sender 内置 WOL 生成器，位于“工具”菜单。

![WOL Tool](screenshots/wake_on_lan_screenshot.png)

填写选项后，主界面会自动填充正确的 WOL 格式数据。

![WOL results](screenshots/wake_on_lan_results_screenshot.png)

此外还有 CLI 选项可帮助生成和发送 WOL 数据包

```text
packetsender --wol f8:23:66:30:e5:30
Sending broadcast Wake-On-LAN to target: F8:23:66:30:E5:30 on port 7
UDP (60360)://255.255.255.255:7 ff ff ff ff ff ff f8 23 66 30 e5 30 f8 23 66 30 e5 30 f8 23 66 30 e5 30 f8 23 66 30 e5 30 f8 23 66 30 e5 30 f8 23 66 30 e5 30 f8 23 66 30 e5 30 f8 23 66 30 e5 30 f8 23 66 30 e5 30 f8 23 66 30 e5 30 f8 23 66 30 e5 30 f8 23 66 30 e5 30 f8 23 66 30 e5 30 f8 23 66 30 e5 30 f8 23 66 30 e5 30 f8 23 66 30 e5 30 f8 23 66 30 e5 30 f8 23 66 30 e5 30 f8 23 66 30 e5 30 f8 23 66 30 e5 30 f8 23 66 30 e5 30 f8 23 66 30 e5 30 f8 23 66 30 e5 30 f8 23 66 30 e5 30 f8 23 66 30 e5 30
```

## SSL 客户端和服务器

Packet Sender 支持通过 SSL 建立加密连接。  
此功能在图形界面（GUI）和命令行中均受支持。

Packet Sender 在 Windows 上捆绑了 OpenSSL。在 Mac 和 Linux 上，Packet Sender 将使用系统原生的 SSL 库。

![Packet Sender Direct TCP](screenshots/packetsender_ssl.PNG)

SSL 注意事项：
* 证书协商在连接建立时立即进行。
* 默认情况下，Packet Sender 会忽略所有 SSL 错误（证书过期、主机名错误、自签名证书等）。
* Packet Sender 会在流量日志中输出证书协商的进度。
* Packet Sender 会在流量日志中输出所使用的加密算法（例如 AES 128）。

Packet Sender 为 Windows 上的服务器模式捆绑了一个内部的“Snake Oil”证书。证书和密钥文件与数据包文件及设置文件位于同一位置。

_注意：在设置中更改证书路径也会同时覆盖 snake-oil 证书。_

如果发生 SSL 错误，Packet Sender 会将其记录到流量日志中。如果设置为“继续”（默认设置），则会继续进行加密协商；否则连接将以连接失败结束。

![Packet Sender Direct TCP Expired](screenshots/packetsender_expired_ssl.png)

## 多播（实验性）

Packet Sender 的多播支持通过尝试向 IPv4 多播地址发送数据或从多播子菜单触发。该功能目前处于实验阶段，并存在以下已知问题：

* 加入多播组后，Packet Sender 会放弃 IPv6 支持。
* 这种放弃状态会持续存在，直到您重新访问设置或尝试向 IPv6 发送数据。
* 在 Wi-Fi 网络上，多播组加入有时需要 20 秒才能真正生效。
* Packet Sender 没有在交换机重启或其他常见错误发生时自动重新加入多播组的逻辑。

目前尚不支持 IPv6 多播，但已列入开发路线图。希望获得 IPv6 多播支持的赞助商欢迎联系我。

<a id="udptraffic"></a>

## UDP 流量生成器（实验性）

当普通发送方式不足以满足需求时，您可以向目标 IP 疯狂发送数据包，测试您的设备能否承受高强度流量。  
此功能位于图形界面工具栏的 _工具 → Intense Traffic Generator_。

请注意，此功能处于实验阶段，显示的指标尚未经过全面验证。如需更准确的测试，建议使用该工具的命令行版本。

![IP Specific binding](screenshots/udp-traffic-sending.PNG)

# Packet Sender 功能


<a id="cloud"></a>
## Packet Sender Cloud

使用免费的 [Packet Sender Cloud](https://cloud.packetsender.com/) 服务，您可以快速保存、获取和共享数据包集。  
Cloud 也可用于公开展示和分发您的数据包（通过 URL），便于协作、编写教程、供最终用户使用等。Packet Sender 支持通过公开 URL 导入公共数据包集。

这样做有多种理由：

* 保留所有数据包，以便全新安装 Packet Sender 时能快速恢复
* 在不同项目之间快速切换数据包集
* 共享登录账号（允许）进行协作式数据包集生成
* 拥有公开的数据包集页面，让其他人可以快速查找并导入

![Packet Sender Cloud Import](screenshots/cloud-import.png)

如果您正在发布网络 API，维护一个公开的 Cloud 页面比逐一痛苦地向用户说明（IP、端口、类型等）要轻松得多。而且更新页面也非常简单。

更多信息请访问  
https://cloud.packetsender.com/help


<a id="portable"></a>
## 便携模式

Packet Sender 支持“便携”模式。启动时会查找 `portablemode.txt` 文件，并在当前运行目录中创建或使用缺失的设置文件。这些文件包括：  
`packets.ini`、`ps_settings.ini`、`ps.key` 和 `ps.pem`。  
您也可以删除 `portablemode.txt` 文件，让部分文件保持便携模式，而其他文件使用系统标准位置。

### 仅控制台便携模式下可删除的 DLL
如果不需要图形界面，可以删除以下 DLL：
- Qt6Svg.dll
- Qt6Widgets.dll
- Qt6Gui.dll
- opengl32sw.dll
- D3Dcompiler_47.dll
- iconengines 目录
- imageformats 目录
- styles 目录

注意：文件名中带有 `+` 字符的 DLL 在 Windows 命令行复制时，如果不使用双引号 `"` 包围，可能会出现问题。

### 不需要安全连接时可删除的 DLL
如果不使用 SSL，可以删除以下 DLL：
- libcrypto-1_1-x64.dll
- libssl-1_1-x64.dll


Windows 用户的运行目录与 .exe 文件所在位置相同。

Mac 用户的运行目录位于 `PacketSender.app/Contents/MacOS`。  
如果在此位置找到 INI 文件，将优先使用它们，而非 `%APPDATA%` 或 `Library/Application Support`。


<a id="smartresponses"></a>
## 智能响应

Packet Sender 支持最多 5 个智能响应。

要启用此功能，请在图形界面工具栏中进入 _文件 → 设置_，切换到 _Smart Responses_ 选项卡，并勾选 **Send a Smart Response** 复选框。

![Packet Sender Direct TCP](screenshots/packetsender_smartreply.PNG)

* Packet Sender 将使用您选择的编码方式比较接收到的数据包。
* 在发送回复前，Packet Sender 会转换编码。
* 支持的编码格式包括：
    * Mixed ASCII —— Packet Sender 标准的混合 ASCII 编码方式（包含不可打印字符）
    * HEX —— Packet Sender 的常规十六进制编码


## 宏

Packet Sender 在发送响应时支持以下宏：

* {{DATE}} —— 发送当前日期，格式为 "yyyy-mm-dd"
* {{TIME}} —— 发送当前时间，格式为 "hh:mm:ss ap"
* {{UNIXTIME}} —— 发送当前 Unix 时间戳（epoch）
* {{COUNTER}} —— 发送递增计数器，每个使用该宏的数据包计数加 1，程序启动时从 1 开始
* {{RANDOM}} —— 发送随机数，范围取决于 32 位或 64 位（Windows 默认安装包为 32 位，Mac 为 64 位）：0~32767 或 0~2147483647
* {{UNIQUE}} —— 发送随机字符串，使用内部 UUID 生成

Packet Sender 会在实际发送前将宏替换为真实值。


<a id="persistent"></a>
## 持久 TCP 和 SSL

Packet Sender 通过独立的图形窗口支持持久 TCP 和 SSL 连接。  
可在主窗口复选框或设置窗口中启用该功能。

![Packet Sender Direct TCP and SSL](screenshots/packetsender_direct_tcp.PNG)

### 持久 TCP 和 SSL 注意事项：
* 可创建任意数量的持久连接
* 可从下拉菜单加载之前保存的数据包
* 提供 “Raw” 和 “ASCII” 两种视图。ASCII 视图有助于排查 Raw 视图中无法显示的数据
* 流量也会记录到主窗口的流量日志中
* 可向持久连接上传文件。建议在此情况下关闭日志记录
* 左下角计时器在发送/接收到有效数据包后立即启动，连接关闭时停止
* 快速发送时可选择按回车键自动附加回车符（\r）。这对通过 TCP/SSL 的命令行菜单非常有用。Packet Sender 会记住 \r 复选框的上次状态
* 服务器接收到的传入持久连接会自动打开独立的图形窗口
* 重发时，持久连接的数据包会携带到新窗口。点击 “Resending(1)” 可取消重发

命令行模式不支持持久连接。


<a id="http"></a>
# HTTP/HTTPS POST & GET
Packet Sender 支持发送 HTTP 和 HTTPS 的 POST/GET 请求。  
协议下拉菜单包含以下选项：HTTP GET、HTTP POST、HTTPS GET、HTTPS POST。  
选择 HTTP(S) 后，输入字段会更新为：名称、Request、Address、Data（POST 时显示）、Generate Data 按钮（POST 时显示）、Load File 按钮（POST 时显示）。

## 发送 HTTP/HTTPS GET/POST 请求
![](/screenshots/ps_http_getfields.PNG)
* 从协议下拉菜单选择 HTTP(S) GET 或 POST
* 在 *Address* 字段输入域名或 IP
* 在 *Request* 字段添加 URL 路径（如果需要）
* 在 *Port* 字段，HTTP 默认 80，HTTPS 默认 443
* 勾选 *Persistent TCP* 可更清晰地查看服务器返回数据（HTTP 头部会自动移除）

**您也可以直接在 Request 字段粘贴完整 URL，Packet Sender 会自动解析并填充其他字段。**

### POST 请求：
* 可手动在 *Data* 字段输入数据  
  格式示例：`key=value`  
  多个参数：`key=value&key=value&key=value`
* 或者点击 *Generate Data* 按钮

<img src="/screenshots/ps_http_datagenerator.PNG" width="400" height="284">

* 输入 Key 和 Value 参数，点击 **+** 按钮添加
* 可通过 + 按钮添加多个参数
* 点击参数旁边的 X 按钮删除
* 添加完成后点击 OK，数据会自动生成到 Data 字段

### 添加身份验证凭证：

<img src="/screenshots/ps_http_authgenerator.PNG" width="800" height="339">

* 进入 文件 → 设置 → HTTP
* 勾选 *Generate Auth Header*
* 输入 *Host*、*UN/Client ID* 和 *PW/Access*
* 点击 *HTTP Auth Header* 生成身份验证头部


<a id="panelgen"></a>
# 面板生成器
Packet Sender 支持生成控制面板。面板由多个按钮组成，每个按钮关联脚本（数据包）。点击按钮将执行该按钮上引用的数据包。

<img src="/screenshots/ps_panel_1.PNG" width="400" height="358">

## 加载面板
面板可以通过以下两种方式创建：
* 点击工具栏上的 **Panels**，选择 Load Starter Panel 或 Empty Panel Project
    * Load Starter Panel 会加载设为启动面板的面板；若未设置启动面板，则打开空面板项目
* 选中 2 个或更多已保存的数据包，然后点击 **Generate Panel** 按钮（仅在选中多个数据包时出现）

Packet Sender 支持使用命令行参数 `--starterpanel` 以仅面板模式启动并加载启动面板

![](/screenshots/ps_panel_generate.PNG)


## 面板脚本编写
要开始为面板按钮编写脚本，请打开一个面板项目并切换到编辑界面。  
打开项目后，检查右下角按钮：如果显示 “Viewing”，则处于查看模式；点击该按钮切换到编辑模式。

进入编辑界面后，即可添加按钮和脚本。

### 按钮脚本
按钮脚本中填写要发送的数据包名称。

<img src="/screenshots/ps_panel_2.PNG" width="400" height="360">

可为一个按钮设置多个数据包，每行填写一个名称。

<img src="/screenshots/ps_panel_5.PNG" width="400" height="358">

面板生成器支持在多个数据包之间添加延迟，方法是在数据包之间插入 `delay:_秒数_`

<img src="/screenshots/ps_panel_4.PNG" width="400" height="359">

面板生成器还支持加载新面板，方法是添加 `panel:_面板ID_`

<img src="/screenshots/ps_panel_8.PNG" width="400" height="358">


### 添加文件/URL
面板生成器支持添加链接到本地文件或网络 URL 的按钮。  
在编辑界面点击右下角的 *+* 按钮即可添加文件/URL 按钮。
* 文件：找到文件 → 右键复制 → 粘贴到 Packet Sender 的 _URL 或 File_ 文本框
* URL：复制链接 → 粘贴到 _URL 或 File_ 文本框  
  （URL 必须以 http:// 或 https:// 开头）

![](/screenshots/ps_panel_7.PNG)

粘贴完成后，系统会提示输入按钮名称。按钮将显示在面板底部。

在编辑界面点击这些按钮可修改链接和按钮名称，也可点击弹窗中的 **X** 删除按钮。

![](/screenshots/ps_http_changeURL.PNG)

在查看界面点击这些按钮将：
- 使用默认浏览器打开 URL
- 使用默认程序打开文件


![](/screenshots/ps_panel_6.PNG)

### 面板编辑与保存
在面板编辑界面会出现包含 File、Export、Settings、Help 的工具栏。  
您可以通过此工具栏保存、导出、导入、加载面板项目并编辑当前项目。

在 Settings 菜单中可执行以下操作：
* Set Panel Name —— 重命名当前面板项目
* Set Panel ID —— 修改当前面板项目的 ID  
  _注意：设置已存在的 ID 将覆盖原有面板_
* Starter Panel —— 将当前面板设为启动面板
* Delete Panel —— 显示当前所有面板列表，选择要删除的面板  
  _注意：删除后按钮和脚本会在编辑界面保留，直到关闭面板_

# DTLS
目前 DTLS 仅在 Windows 的图形界面中支持。其他操作系统可通过使用 Qt6 从源代码编译来启用。

## 概述
此仓库包含 DTLS（数据报传输层安全）协议功能。该功能增加了图形界面，用于配置和管理 DTLS 连接，包括服务器验证和会话持久化选项。

## 功能

### 主窗口
![Main Window](screenshots/main_window.png)
- **Cipher Suites**：下拉菜单选择 DTLS 通信所需的密码套件
- **Server Common Name**：输入服务器通用名称，用于客户端验证
- **Persistent Session**：勾选持久化复选框后，在首次握手后保存会话密钥
- **Optional Server Verification**：启用握手期间的双向验证
- **DTLS Server Port**：定义 DTLS 服务器端口的按钮

#### 附加图片：
![Cipher Suites Dropdown](screenshots/cipher_suites.png)
- 密码套件选择下拉菜单的详细视图

![Persistent Connection](screenshots/persistant_dtls.jpg)
- DTLS 持久连接窗口

![Server Port](screenshots/server_ports.png)
- 点击按钮启用或禁用 DTLS 服务器

### 设置窗口

#### 网络选项卡
![Network Tab](screenshots/settings.png)
- **Send Simple Acknowledge**：启用发送简单确认
- **Enable DTLS Server**：启用 DTLS 服务器并选择端口
- **Certificates and Keys**：证书和密钥加载方式与 SSL 配置类似

#### 智能响应选项卡
![Smart Responses Tab](screenshots/settings_2.png)
- **Smart Responses**：智能响应功能支持在 DTLS 协议上运行

## Wireshark 集成
使用 Wireshark 抓包：

### 普通连接
![Regular Connection](screenshots/wireshark_simple_session.png)
- Wireshark 捕获的普通 DTLS 连接示例

### 持久连接
![Persistent Connection](screenshots/wireshark_persistent_connection.png)
- Wireshark 捕获的持久 DTLS 连接示例

<a id="cli"></a>
# 命令行
Packet Sender 支持通过命令行在计算机上使用。

Windows 用户请使用 `.com` 扩展名（`packetsender.com`）进入命令行界面。  
也可以不带扩展名直接使用 `packetsender`。使用 `.exe` 扩展名会启动图形界面。


![Packet Sender CLI screenshot](screenshots/packetsender_command_line.png)

Linux 用户的命令行遵循与其他 Linux 工具相同的模式：支持长选项（如 --version）和短选项（如 -v），选项顺序任意，Packet Sender 会正确解析。  
最后三个参数是位置参数，必须放在最后：IP、端口、数据。  
如果使用已保存的数据包，则这三个参数可选。

```text
packetsender --help
Usage: C:\Program Files\PacketSender\packetsender.com [options] address port data
Packet Sender is a Network UDP/TCP/SSL/HTTP Test Utility by NagleCode
See https://PacketSender.com/ for more information.

Options:
  -h, --help                Displays help on commandline options.
  --help-all                Displays help including Qt specific options.
  -v, --version             Displays version information.
  -q, --quiet               Quiet mode. Only output received data.
  -x, --hex                 Parse data-to-send as hex (default for
                            TCP/UDP/SSL).
  -a, --ascii               Parse data-to-send as mixed-ascii (default for http
                            and GUI).
  -A, --ASCII               Parse data-to-send as pure ascii (no \xx
                            translation).
  -l, --listen              Listen instead of send. Use bind options to specify
                            port/IP. Otherwise, dynamic/All.
  -r, --response <ascii>    Server mode response data in mixed-ascii. Macro
                            supported.
  -w, --wait <ms>           Wait up to <milliseconds> for a response after
                            sending. Zero means do not wait (Default).
  -f, --file <path>         Send contents of specified path. Max 10 MiB for
                            UDP, 100 MiB for TCP/SSL.
  -b, --bind <port>         Bind port. Default is 0 (dynamic).
  -6, --ipv6                Force IPv6. Same as -B "::". Default is IP:Any.
  -4, --ipv4                Force IPv4.  Same as -B "0.0.0.0". Default is
                            IP:Any.
  -B, --bindip <IP>         Bind custom IP. Default is IP:Any.
  -t, --tcp                 Send TCP (default).
  -s, --ssl                 Send SSL and ignore errors.
  -S, --SSL                 Send SSL and stop for errors.
  -u, --udp                 Send UDP.
  --http <http>             Send HTTP. Allowed values are GET (default) and
                            POST
  -n, --name <name>         Send previously saved packet named <name>. Other
                            options overrides saved packet parameters.
  --wol <mac>               Send Wake-On-LAN / Magic Packet to <mac> and
                            (optional) <port>.
  --bps <bps>               Intense traffic. Calculate rate based on value of
                            bits per second.
  --num <number>            Intense traffic. Number of packets to send. Default
                            unlimited.
  --rate <Hertz>            Intense traffic. Rate. Ignored in bps option.
  --usdelay <microseconds>  Intense traffic. Resend delay. Used if rate is 0.
                            Ignored in bps option.
  --max                     Intense traffic. Run as fast as possible.

Arguments:
  address                   Destination address/URL. Optional for saved packet.
  port                      Destination port/POST data. Optional for saved
                            packet.
  data                      Data to send. Optional for saved packet.
```

## 示例 CLI

CLI 在 Windows、Linux 和 Mac 上遵循相同的格式。

格式为：`packetsender [options] address port data`

```text
packetsender -taw 500 mirrors.xmission.com 21 "USER anonymous\r\nPASS chrome@example.com\r\n"
TCP (65505)://mirrors.xmission.com:21 55 53 45 52 20 61 6e 6f 6e 79 6d 6f 75 73 0d 0a 50 41 53 53 20 63 68 72 6f 6d 65 40 65 78 61 6d 70 6c 65 2e 63 6f 6d 0d 0a
Response Time:5:51:37.042 pm
Response HEX:32 32 30 2D 57 65 6C 63 6F 6D 65 20...
Response ASCII:220-Welcome to XMission Internet...
```

## 示例 CLI：监听数据包（服务器模式）

使用现有的绑定选项来配置服务器：
- `-b` 用于指定端口
- `-B` 用于指定 IP
- `-t` / `-u` / `-s` 用于 TCP、UDP 或 SSL
- `-r` 用于发送响应（支持 ASCII 格式的宏）

绑定到动态端口使用 TCP

```text
packetsender -l
TCP Server started on 0.0.0.0:52567
Use ctrl+c to exit server.

From: 127.0.0.1, Port:52568
Response Time:2024-06-04 19:01:53.198
Response HEX:48 65 6C 6C 6F 
Response ASCII:Hello

From: 127.0.0.1, Port:52569
Response Time:2024-06-04 19:02:24.063
Response HEX:57 6F 72 6C 64 
Response ASCII:World
```

绑定到端口 8080 使用 UDP

```text
packetsender -l -u -b 8080
UDP Server started on 0.0.0.0:8080
Use ctrl+c to exit server.

From: ::ffff:127.0.0.1, Port:49500
Response Time:2024-06-04 19:04:28.890
Response HEX:48 65 6C 6C 6F 20 55 44 50 20 50 61 63 6B 65 74 
Response ASCII:Hello UDP Packet
```

绑定到端口 8080 使用 UDP 并返回当前时间响应

```text
packetsender -l -u -b 8080 -r "{{TIME}}"
Loading response packet.
UDP Server started on 0.0.0.0:8080
Use ctrl+c to exit.

From: ::ffff:127.0.0.1, Port:59594
Response Time:2024-06-05 20:48:18.180
Response HEX:68 65 6C 6C 6F 20 70 61 63 6B 65 74 20 73 65 6E 64 65 72 
Response ASCII:hello packet sender

From: You (Response), Port:59594
Response Time:2024-06-05 20:48:18.182
Response HEX:30 38 3a 34 38 3a 31 38 20 70 6d 
Response ASCII:08:48:18 pm
```

绑定到 IP 192.168.86.26，端口 54321 使用 SSL

```text
packetsender -l -s -B 192.168.86.26 -b 54321 
Binding to custom IP 192.168.86.26
Listening for SSL packets in server mode. 
SSL Server started on 192.168.86.26:54321
Use ctrl+c to exit server.

From: 192.168.86.26, Port:52588
Response Time:2024-06-04 19:11:30.726
Error/Info:Encrypted with AESGCM(256)

From: 192.168.86.26, Port:52588
Response Time:2024-06-04 19:11:30.726
Error/Info:Authenticated with RSA

From: 192.168.86.26, Port:52588
Response Time:2024-06-04 19:11:30.726
Error/Info:Peer cert issued by 

From: 192.168.86.26, Port:52588
Response Time:2024-06-04 19:11:30.726
Error/Info:Our Cert issued by SnakeOil

From: 192.168.86.26, Port:52588
Response Time:2024-06-04 19:11:30.747
Response HEX:43 6F 6F 6C 20 53 53 4C 
Response ASCII:Cool SSL
```

## 示例：绑定端口和自定义 IP、IPv4 或 IPv6

Packet Sender 的命令行可以通过 `-B` 选项绑定自定义端口，以强制使用 IPv4/6 模式或指定多网卡（NIC）。

```text
packetsender -taw 3000 fe80::c07b:d517:e339:5a08 5005 "Hello\r"
packetsender -taw 3000 192.168.0.201 5005 "Hello\r"
packetsender -B 192.168.0.200 -taw 3000 192.168.0.201 5005 "Hello\r"
packetsender -B fe80::a437:399a:3091:266a%ethernet_32769 -taw 3000 fe80::c07b:d517:e339:5a08 5005 "Hello\r"
packetsender -B fe80::a437:399a:3091:266a -taw 3000 fe80::c07b:d517:e339:5a08 5005 "Hello\r"
```

## 示例 CLI：使用 SSL 并忽略错误

命令行支持选择忽略 SSL 错误或在出现错误时中止。默认行为是忽略。

* 使用 `-s` 选项发送 SSL 并忽略错误。
* 使用 `-S` 选项发送 SSL 并在出现错误时停止。

```text
packetsender -saw 500 expired.packetsender.com 443 "GET / HTTP/1.0\r\n\r\n"
SSL Error: The certificate has expired
SSL (54202)://expired.packetsender.com:443 47 45 54 20 2f 20 48 54 54 50 2f 31 2e 30 0d 0a 0d 0a
Cipher: Encrypted with AES(128)

Response Time:3:24:55.695 pm
Response HEX:48 54 54 50 2f 31 2e 31 20 34 32 31 20 0d 0a 53 65 72 76 65 72 3a 20 6e 67 69 6e 78 2f 31 2e 31 30 2e 30 20 28 55 62 75 6e 74 75 29 0d
Response ASCII:HTTP/1.1 421 \r\nServer: nginx/1.10.0 (Ubuntu)\r
```

## 示例 CLI：使用 HTTP

注意：此示例使用内置的默认数据包。

```text
packetsender --name "HTTPS POST Params"
packetsender --http GET "https://httpbin.org/get"
packetsender --http POST "https://httpbin.org/post" "{}"
```

<a id="cliintensetraffic"></a>

## 示例：使用 CLI 高强度流量生成器

命令行高强度流量生成器的工作方式与图形界面版本基本相同，但精度稍高、控制选项更多（强度也更高！）。

下面是一些使用示例。请注意，这些计算属于“尽力而为”（Best Effort）。它表现良好，但处理器峰值或网络抖动等因素可能会影响实际效果。线程不是实时线程，补偿机制也不够智能。

* 以 20 Hz 的频率重发 "My Awesome Packet"
* 以 2000 baud（bps）的速率重发 "My Awesome Packet"
* 以最快速度重发 "My Awesome Packet"
* 以每个数据包之间 2000000 微秒的延迟重发 "My Awesome Packet"

**注意：Windows 用户请使用 ".com" 构建版本，因此每个示例中应使用 packetsender.com**

```text
packetsender --rate 20 --name "My Awesome Packet"
packetsender --bps 2000 --name "My Awesome Packet"
packetsender --rate 0 --name "My Awesome Packet"
packetsender --usdelay 2000000 --name "My Awesome Packet"
```

<a id="building"></a>
# 编译 Packet Sender

唯一依赖是 Qt SDK

## 为 Windows 和 Mac 编译 Packet Sender
1. 从 https://www.qt.io/download-open-source/ 下载 Qt 安装程序
1. 如果您没有编译器，让它安装 MinGW。
1. 打开项目文件 PacketSender.pro
1. 编译！

Windows 和 Mac 版本使用 Qt 5.12 构建。Packet Sender 也支持 Qt 6，但不支持 cmake。

## 为 Linux 编译 Packet Sender
以下是 Ubuntu 16.04 的命令序列。请根据您的 Linux 发行版进行调整。Packet Sender 除了标准 Qt SDK 之外不需要任何额外库。据反馈，Fedora 原版存在编译问题。如果有 Fedora 高手有经验，请告诉我，我会添加您的说明。

如果您想冒险，可以从 master 分支编译。它包含最新的稳定版本。development 分支大概应该避免使用。

```bash
sudo apt-get update
sudo apt-get install qt5-default build-essential
wget https://github.com/dannagle/PacketSender/archive/(Version).tar.gz
tar -xzvf (Version).tar.gz
cd PacketSender-(Version)/src
qmake PacketSender.pro
make
```

运行方式：
```text
./PacketSender
```

如果无法运行，您可能需要为其设置可执行权限

```text
chmod a+x PacketSender
```

# 增强功能/需求

缺少某项功能？您可以[雇佣我将其添加到 Packet Sender](https://packetsender.com/enhancements)。

# 法律 / 合规

许可协议为 GPL v2 或更高版本。如果您需要其他许可，请[联系我](https://packetsender.com/contact)。
部分 Packet Sender 发行版可能会使用 [OpenSSL](https://www.openssl.org/)。
最新的 VPAT [可在此仓库中找到](vpat_2.4_packetsender.pdf)。


# 版权

Packet Sender 由 [Dan Nagle](https://dannagle.com/) 编写，由 &copy; NagleCode, LLC 发布   -  [@NagleCode](https://x.com/NagleCode) - [PacketSender.com](https://packetsender.com)
