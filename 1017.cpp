尝试了很多次，有不少测试点没通过，不知道漏洞在哪。我觉得我的思路比较简洁（见下面），至少比模拟时间一秒一秒模拟要好些。
思路：
struct Man *M //所有的客户（含：到达时间arrival, 开始办理时间begin, 处理时间proc）
int *W //所有的窗口(代表该窗口开始工作并空闲的时间点，初始值为head, 及8点)
1，先将M数组排序，用sort内置函数。把客户按照到达时间arrival排序（使用cmp比较函数）
    默认窗口已从小到大排好
2，M[]客户从头到尾依次求出begin值。
    （1）每个M[i]，max(arrival, W[0]<开始空闲最早的窗口>) 作为M[i]客户begin值。
    （2）根据begin+proc求出该窗口处理完W[i]用户后开始空闲的时间点作为W[0]的新值
    （3）类似插入排序算法，把W[0]依次往后（只要后面的比它小）
    （4）i++,返回（1）
3，依次统计符合条件的客户的等待时间（begin-arrival），求出平均等待时间