# 都市浮生记

花了八天时间，跟着视频用c++完成了《都市浮生记》这个基于文字的游戏的半成品，游戏本身不涉及图片，所以可以不必考虑easyx图形库的使用，我可以更加专心于c++语言本身的实现。这个项目（我不知道这个配不配称为项目），属于那种自己刚好能看懂，刚好在能力范围的边界上的项目，里面有很多很多新鲜的概念和编程方法，这也是我一直希望得到的东西。学校里学编程语言，仅仅是专注于教我们如何使用这个工具，完全没有使用的机会，工具学的再熟，不用的话不久就全忘了。 在这个项目中，我第一次深刻体会到面向对象编程的意义。由于是疯了一样一遍看视频一遍照着写代码，很多地方没有深刻理解那样写的含义，现在要做一个代码的整理工作，包括逻辑的理顺，注释的重写，变量命名的规范，代码风格的统一等。

## 新鲜东西

1. MVC模式，指的是Model，View，Control三个部分的代码互相独立，分工明确，模型层负责游戏中需要用到的各种数据的初始化和加载，显示层负责用好看的方式显示游戏数据，控制层负责调用数据层的数据以及显示层的方法，处理用户输入相关的操作，以及游戏内核。什么叫处处都是类，游戏模型可以抽象成类容易理解，控制器和视图也可以抽象成很多类。每一层的几个小类又可以合并起来抽象成一个中类，几个中类又可以合并为一个大类里综合考虑。单独看每个类，里面的代码都很容易理解，但是一旦合并起来，要综合考虑程序先干了啥后干了啥是很不容易的。

2. 单例设计模式，据说是最简单的设计模式，由于此项目不涉及多线程，采用了简单的懒汉式，即在类中定义私有静态指针指向自己，并提供一个公有的静态类进行初始化，这样做保证了该类在整个过程中只有一个示例（原因我还不大理解）。用起来很方便，也是我之前没有接触过的概念和方法，非常有趣。游戏中很多对象的确只能有一个示例。

3. system函数的使用，终于明白这个函数的作用了，是提供一个借口，让我们可以调用cmd的命令，从而做到控制命令行窗口的大小背景颜色字体颜色等参数，这样一系列操作可以放在main函数中统一进行实现。但是main.cpp中的函数定义为什么都加了extern关键字？

4. 字符串拼接，终于理解了在c++中stream（流）的真正含义，之前有<iostream>标准输入输出流以及<fstream>文件流，这几天又知道了还有<sstream>字符串流，统一起来看，它们有很多共同点，举一反三的使用。在游戏制作中，字符串流用处很大。字符串流不是字符串，使用时要调用str()方法转化为string类型。

5. 调用windowsAPI进行音乐和音效的播放，其中坑很多，坑很多。头文件使用如下：

```c++
#include <windows.h>//一定要放在前面
#include <Mmsystem.h>
#pragma comment(lib,"winmm.lib")
```

​	以下方法是控制播放和停止，该函数尚不熟练，暂且知道是这么用的吧。具体使用见源码SoundController类。

```c++
PlaySound(TEXT("sound/bgm1.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
PlaySound(TEXT(NULL), NULL, SND_FILENAME);
mciSendString(cmd.str().c_str(), 0, 0, NULL);
mciSendString(cmd.str().c_str(), 0, 0, NULL);
```

​	为了使用方便，音频源文件名称可以不用描述性的文字，直接用编号表示，只要在文档中说明一下即可，体现灵活性，用外部手段减轻	代码量。

6. 有时候类方法之间的相互调用很时混乱，暂时没有实力去改，比如开始游戏的时候，View中选择新游戏后，调用了GameCore中的方法，该方法又返回来调用View中的方法。

## 各类功能说明和改进方案

1. Control
   1. GameControl类，单例类，负责控制游戏开场和结束分别要做什么操作。开场播放背景音乐，播放剧情动画，之后显示系统菜单。游戏结束，......（尚未完成）
   2. SoundController类，单例类，负责控制游戏音乐的播放。有一个bool  silence属性用来记录当前有没有在播放音乐，true为静音状态，默认为false。此类算是封装的比较独立的类，将关于音乐的实现方法都打包在一起。
   3. GameCore类，单例类，游戏内核，非常重要，是整个游戏的核心，该类中的GameOver是指游戏结束后的数据操作，区别于Viewer中的EndGame是游戏结束的数据展示；此类中的更新黑市数据的算法非常非常值得关注
2. Model
   1. GameWorld类，单例类，用于综合管理游戏当前事件，游戏最大时间，游戏人物，游戏场景，游戏地铁站，游戏事件，游戏当前事件。这些信息各有不同的处理方法（还不理解其中原因），比如所有物品和所有事件用map来存储，而游戏场景和地铁站都用vector，再比如为什么游戏人物的信息就采用类似单例的模式使用，而其他的不用，再比如对游戏消息的处理为什么不像游戏地点一样在该类中数据初始化，而要到EventController中数据初始化。此类有点混乱，很多处理上不统一，理解起来困难。
   2. GameRole类，并非直接的单例类，但在GameWorld中做了类似单例类的处理，游戏只有一个玩家。包含了玩家的基本属性，所有物，人物可能作出的动作（目前只有一个出售的动作）；该类中的storeGood是用vector类型存储的，区别于GameWorld中用map存储
   3. GamePlace类，没什么存在感，仅包含地点的基本属性
   4. GameGood类，注意没有s，于GamePlace类类似，没什么存在感，唯一要注意的是属性中value和buyPrice是不一样的概念。
   5. Station类，一个地铁站拥有一个黑市，该类中体现了两个类生存周期的管理控制，可是Station的析构什么时候调用？很多代码放在那儿，不敢删，也不知道有啥用
   6. BlackMarket类，包含了黑市的动作（目前只有一个sell），商品列表，而该列表要到GameCore中进行赋值，又是一个不一样的操作
   7. Message类，其属性包含了所有可能的，事件能影响的因子
3. View
   1. Viewer类，单例类，负责播放游戏开场动画（该方法的实现值得注意，很简单很巧妙），显示并处理输入主菜单、系统菜单、游戏设置菜单以及游戏结束界面（处理的细节并不在此处），由于该游戏菜单很多而格式又差不多，在该类中封装了一个函数专门用来显示菜单项（其实现方法值得注意）。暂时还有很多菜单功能没有实现。该类有一个主面板实例的指针属性，有点不明白该类和GameInfoView以及GameMainView之间的关系是什么。
   2. GameInfoView类，游戏面板的显示此程序使用了将面板拆分为多个，每个分别用类来控制，而此类就是所有显示面板类的基类，负责显示共性的东西，游戏天数，随机事件，玩家信息属性的面板。难理解之处在于把显示格式弄好看的算法。该类有个人物属性是我没法理解的，又没有做到单例化。我只能理解为要显示啥就把啥作为属性。后面的MarketView类也是如此
   3. MarketView类，有一个Creat函数类似于单例，但这样处理有点不明白其原因

## 游戏规则

见“游戏规则.docx”

## 未来想法

1. 是不是可以采用文件操作，提供一个选项，将游戏关键数据存到文件里，实现一个存档功能。
2. 目前的半成品游戏仅仅实现一个地铁站的功能，之后要把其他地图都开放了。
3. 地铁站数量太多，还是易于刷钱，可以设计成每天限制进入几个地铁站，每个地铁站之间没有特殊性，哪一个的黑市都是随机的
4. 黑市的出售购买还存在问题，若黑市没有某个商品，无法出售该商品
5. 代码变量太多之后，命名出现混乱，要整治这个问题
6. 单例设计模式是不是会出现内存泄漏的现象？寻找解决方法
7. 游戏中的很多参数能不能放到同一个头文件中？
8. 是不是可以添加白天黑夜，拓展玩法

## BUG

1. 第一天就存在利息
2.  家具城买床后第二天不扣健康值，第三天开始扣
