import pytest

import re
class TestBase:
    def metadata_format(file_path):
        """
        Check if the given Markdown file has the expected metadata format.
        """
        with open(file_path, 'r', encoding='utf-8') as f:
            content = f.read()
            
            # Check if the file starts with the expected metadata format
            metadata = re.match(r'---\s*\n(?:title:\s*"(?P<title>[\w.\- ]+)"\s*\n)?(?:Difficulty:\s*"(?P<difficulty>\w+)"\s*\n)?(?:tags:\s*\[(?P<tags>[\w\s,"]*)\]\s*\n)?---', content)
            if metadata is None:
                pytest.fail(f'Metadata format is missing or incorrect')
            
            difficulty = metadata.group('difficulty')
            tags = metadata.group('tags')
            title = metadata.group('title')
            extra_properties = metadata.group(3)
            
            # Check if Difficulty and tags are present
            if difficulty is None:
                pytest.fail(f'Difficulty is missing')
            if tags is None:
                pytest.fail(f'Tags is missing')
            
            # Check for extra properties
            pass  # Ignore the "title" property
@pytest.mark.parametrize("file_path", ["leetcode/100121. 查找包含给定字符的单词.md"])
def test_100121(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/100133. 购买水果需要的最少金币数.md"])
def test_100133(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/100138. 最大化网格图中正方形空洞的面积.md"])
def test_100138(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/100242. 满足距离约束且字典序最小的字符串.md"])
def test_100242(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/100264. 最长的严格递增或递减子数组.md"])
def test_100264(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/1004. 最大连续1的个数 III.md"])
def test_1004(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/1019. 链表中的下一个更大节点.md"])
def test_1019(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/1026. 节点与其祖先之间的最大差值.md"])
def test_1026(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/1038. 从二叉搜索树到更大和树.md"])
def test_1038(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/105. 从前序与中序遍历序列构造二叉树.md"])
def test_105(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/1068. 产品销售分析 I.md"])
def test_1068(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/1094. 拼车.md"])
def test_1094(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/11. 盛最多水的容器.md"])
def test_11(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/1146. 快照数组.md"])
def test_1146(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/118. Pascal's Triangle.md"])
def test_118(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/120. Triangle.md"])
def test_120(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/1207. 独一无二的出现次数.md"])
def test_1207(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/1234. 替换子串得到平衡字符串.md"])
def test_1234(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/1239. Maximum Length of a Concatenated String with Unique Characters.md"])
def test_1239(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/124. 二叉树中的最大路径和.md"])
def test_124(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/1261. 在受污染的二叉树中查找元素.md"])
def test_1261(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/1312. 让字符串成为回文串的最少插入次数.md"])
def test_1312(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/132. 分割回文串 II.md"])
def test_132(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/1329. 将矩阵按对角线排序.md"])
def test_1329(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/1347. Minimum Number of Steps to Make Two Strings Anagram.md"])
def test_1347(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/1372. 二叉树中的最长交错路径.md"])
def test_1372(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/1379. 找出克隆二叉树中的相同节点.md"])
def test_1379(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/139. Word Break.md"])
def test_139(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/1410. HTML 实体解析器.md"])
def test_1410(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/1423. 可获得的最大点数.md"])
def test_1423(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/1457. 二叉树中的伪回文路径.md"])
def test_1457(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/1475. 商品折扣后的最终价格.md"])
def test_1475(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/1483. 树节点的第 K 个祖先.md"])
def test_1483(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/1491. 去掉最低工资和最高工资后的工资平均值.md"])
def test_1491(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/15. 三数之和.md"])
def test_15(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/150. Evaluate Reverse Polish Notation.md"])
def test_150(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/1544. Make The String Great.md"])
def test_1544(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/1553. 吃掉 N 个橘子的最少天数.md"])
def test_1553(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/1561. Maximum Number of Coins You Can Get.md"])
def test_1561(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/1600. 王位继承顺序.md"])
def test_1600(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/162. 寻找峰值.md"])
def test_162(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/1637. Widest Vertical Area Between Two Points Containing No Points.md"])
def test_1637(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/1657. 确定两个字符串是否接近.md"])
def test_1657(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/1658. 将 x 减到 0 的最小操作数.md"])
def test_1658(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/167. 两数之和 II - 输入有序数组.md"])
def test_167(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/1670. 设计前中后队列.md"])
def test_1670(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/1671. 得到山形数组的最少删除次数.md"])
def test_1671(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/1683. 无效的推文.md"])
def test_1683(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/1685. Sum of Absolute Differences in a Sorted Array.md"])
def test_1685(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/1686. 石子游戏 VI.md"])
def test_1686(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/1696. 跳跃游戏 VI.md"])
def test_1696(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/17. Letter Combinations of a Phone Number.md"])
def test_17(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/1702. 修改后的最大二进制字符串.md"])
def test_1702(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/1704. Determine if String Halves Are Alike.md"])
def test_1704(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/1727. Largest Submatrix With Rearrangements.md"])
def test_1727(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/1738. 找出第 K 大的异或坐标值.md"])
def test_1738(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/1757. 可回收且低脂的产品.md"])
def test_1757(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/1793. 好子数组的最大分数.md"])
def test_1793(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/1814. Count Nice Pairs in an Array.md"])
def test_1814(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/1883. 准时抵达会议现场的最小跳过休息次数.md"])
def test_1883(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/191. Number of 1 Bits.md"])
def test_191(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/1913. Maximum Product Difference Between Two Pairs.md"])
def test_1913(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/1944. 队列中可以看到的人数.md"])
def test_1944(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/1953. 你可以工作的最大周数.md"])
def test_1953(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/1969. 数组元素的最小非零乘积.md"])
def test_1969(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/1997. 访问完所有房间的第一天.md"])
def test_1997(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/2007. 从双倍数组中还原原数组.md"])
def test_2007(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/2009. 使数组连续的最少操作数.md"])
def test_2009(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/205. Isomorphic Strings.md"])
def test_205(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/2085. 统计出现过一次的公共字符串.md"])
def test_2085(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/209. 长度最小的子数组.md"])
def test_209(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/2129. 将标题首字母大写.md"])
def test_2129(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/216. 组合总和 III.md"])
def test_216(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/2171. 拿出最少数目的魔法豆.md"])
def test_2171(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/2192. 有向无环图中一个节点的所有祖先.md"])
def test_2192(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/22. Generate Parentheses.md"])
def test_22(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/221. Maximal Square.md"])
def test_221(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/2216. 美化数组的最少删除数.md"])
def test_2216(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/2225. 找出输掉零场或一场比赛的玩家.md"])
def test_2225(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/2246. 相邻字符不同的最长路径.md"])
def test_2246(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/225. 用队列实现栈.md"])
def test_225(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/228. Summary Ranges.md"])
def test_228(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/2304. 网格中的最小路径代价.md"])
def test_2304(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/2312. 卖木头块.md"])
def test_2312(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/232. 用栈实现队列.md"])
def test_232(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/2336. 无限集中的最小数字.md"])
def test_2336(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/2342. 数位和相等数对的最大和.md"])
def test_2342(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/2356. 每位教师所教授的科目种类的数量.md"])
def test_2356(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/2369. 检查数组是否存在有效划分.md"])
def test_2369(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/242. Valid Anagram.md"])
def test_242(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/2433. 找出前缀异或的原始数组.md"])
def test_2433(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/2444. Count Subarrays With Fixed Bounds.md"])
def test_2444(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/2476. 二叉搜索树最近节点查询.md"])
def test_2476(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/2487. 从链表中移除节点.md"])
def test_2487(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/2529. 正整数和负整数的最大计数.md"])
def test_2529(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/2538. 最大价值和与最小价值和的差值.md"])
def test_2538(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/2575. 找出字符串的可整除数组.md"])
def test_2575(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/2580. 统计将重叠区间合并成组的方案数.md"])
def test_2580(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/2581. 统计可能的树根数目.md"])
def test_2581(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/2583. 二叉树中的第 K 大层和.md"])
def test_2583(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/260. Single Number III.md"])
def test_260(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/2617. 网格图中最少访问的格子数.md"])
def test_2617(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/264. Ugly Number II.md"])
def test_264(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/2645. 构造有效字符串的最少插入数.md"])
def test_2645(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/2646. 最小化旅行的价格总和.md"])
def test_2646(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/2661. 找出叠涂元素.md"])
def test_2661(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/2670. 找出不同元素数目差数组.md"])
def test_2670(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/2671. 频率跟踪器.md"])
def test_2671(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/2673. 使二叉树所有路径值相等的最小代价.md"])
def test_2673(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/2696. 删除子串后的字符串最小长度.md"])
def test_2696(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/2707. 字符串中的额外字符.md"])
def test_2707(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/2739. 总行驶距离.md"])
def test_2739(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/274. H-Index.md"])
def test_274(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/2765. 最长交替子数组.md"])
def test_2765(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/2766. 重新放置石块.md"])
def test_2766(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/2786. 访问数组中的位置使分数最大.md"])
def test_2786(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/2789. 合并后数组中的最大元素.md"])
def test_2789(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/2807. 在链表中插入最大公约数.md"])
def test_2807(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/2809. 使数组和小于等于 x 的最少时间.md"])
def test_2809(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/2810. 故障键盘.md"])
def test_2810(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/2813. 子序列最大优雅度.md"])
def test_2813(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/2824. 统计和小于目标的下标对数目.md"])
def test_2824(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/2831. 找出最长等值子数组.md"])
def test_2831(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/2834. 找出美丽数组的最小和.md"])
def test_2834(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/2840. Check if Strings Can be Made Equal With Operations II.md"])
def test_2840(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/2846. 边权重均等查询.md"])
def test_2846(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/2859. 计算 K 置位下标对应元素的和.md"])
def test_2859(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/2861. 最大合金数.md"])
def test_2861(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/2864. 最大二进制奇数.md"])
def test_2864(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/2865. 美丽塔 I.md"])
def test_2865(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/2866. 美丽塔 II.md"])
def test_2866(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/2867. 统计树中的合法路径数目.md"])
def test_2867(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/29. Divide Two Integers.md"])
def test_29(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/2923. 找到冠军 I.md"])
def test_2923(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/2928. 给小朋友们分糖果 I.md"])
def test_2928(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/2938. 区分黑球与白球.md"])
def test_2938(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/2958. Length of Longest Subarray With at Most K Frequency.md"])
def test_2958(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/2960. Count Tested Devices After Test Operations.md"])
def test_2960(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/2962. Count Subarrays Where Max Element Appears at Least K Times.md"])
def test_2962(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/299. 猜数字游戏.md"])
def test_299(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/3. 无重复字符的最长子串.md"])
def test_3(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/300. Longest Increasing Subsequence.md"])
def test_300(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/303. 区域和检索 - 数组不可变.md"])
def test_303(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/3038. 相同分数的最大操作数目 I.md"])
def test_3038(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/3067. 在带权树网络中统计可连接服务器对数目.md"])
def test_3067(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/3072. 将元素分配到两个数组中 II.md"])
def test_3072(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/3083. 字符串及其反转中是否存在同一子字符串.md"])
def test_3083(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/3084. 统计以给定字符开头和结尾的子字符串总数.md"])
def test_3084(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/3085. 成为 K 特殊字符串需要删除的最少字符数.md"])
def test_3085(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/3090. Maximum Length Substring With Two Occurrences.md"])
def test_3090(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/3099. 哈沙德数.md"])
def test_3099(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/32. Longest Valid Parentheses.md"])
def test_32(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/332. 重新安排行程.md"])
def test_332(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/337. House Robber III(extra).md"])
def test_337(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/337. 打家劫舍 III.md"])
def test_337(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/365. 水壶问题.md"])
def test_365(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/375. 猜数字大小 II.md"])
def test_375(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/377. 组合总和 Ⅳ.md"])
def test_377(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/387. First Unique Character in a String.md"])
def test_387(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/39. Combination Sum.md"])
def test_39(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/39. 组合总和.md"])
def test_39(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/409. Longest Palindrome.md"])
def test_409(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/419. 甲板上的战舰.md"])
def test_419(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/42. 接雨水.md"])
def test_42(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/447. 回旋镖的数量.md"])
def test_447(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/462. 最小操作次数使数组元素相等 II.md"])
def test_462(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/5. Longest Palindromic Substring.md"])
def test_5(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/514. 自由之路.md"])
def test_514(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/516. Longest Palindromic Subsequence.md"])
def test_516(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/516. 最长回文子序列.md"])
def test_516(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/518. 零钱兑换 II.md"])
def test_518(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/53. 最大子数组和.md"])
def test_53(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/57. Insert Interval.md"])
def test_57(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/58. Length of Last Word.md"])
def test_58(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/589. N 叉树的前序遍历.md"])
def test_589(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/590. N 叉树的后序遍历.md"])
def test_590(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/606. Construct String from Binary Tree.md"])
def test_606(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/62. Unique Paths.md"])
def test_62(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/63. Unique Paths II .md"])
def test_63(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/64. Minimum Path Sum.md"])
def test_64(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/661. Image Smoother.md"])
def test_661(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/670. 最大交换.md"])
def test_670(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/687. 最长同值路径.md"])
def test_687(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/689. 三个无重叠子数组的最大和.md"])
def test_689(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/70. Climbing Stairs.md"])
def test_70(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/705. 设计哈希集合.md"])
def test_705(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/706. 设计哈希映射.md"])
def test_706(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/712. Minimum ASCII Delete Sum for Two Strings.md"])
def test_712(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/713. 乘积小于 K 的子数组.md"])
def test_713(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/72. Edit Distance.md"])
def test_72(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/739. 每日温度.md"])
def test_739(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/740. Delete and Earn.md"])
def test_740(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/746. 使用最小花费爬楼梯.md"])
def test_746(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/82. 删除排序链表中的重复元素 II.md"])
def test_82(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/828. 统计子串中的唯一字符.md"])
def test_828(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/83. 删除排序链表中的重复元素.md"])
def test_83(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/867. Transpose Matrix.md"])
def test_867(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/872. Leaf-Similar Trees.md"])
def test_872(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/889. 根据前序和后序遍历构造二叉树.md"])
def test_889(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/894. 所有可能的真二叉树.md"])
def test_894(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/907. 子数组的最小值之和.md"])
def test_907(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/924. 尽量减少恶意软件的传播.md"])
def test_924(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/931. Minimum Falling Path Sum.md"])
def test_931(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/935. 骑士拨号器.md"])
def test_935(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/938. 二叉搜索树的范围和.md"])
def test_938(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/94. Binary Tree Inorder Traversal.md"])
def test_94(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/968. 监控二叉树.md"])
def test_968(file_path):
    TestBase.metadata_format(file_path)

@pytest.mark.parametrize("file_path", ["leetcode/992. Subarrays with K Different Integers.md"])
def test_992(file_path):
    TestBase.metadata_format(file_path)

