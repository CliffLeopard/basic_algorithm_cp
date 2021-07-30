## 十种排序算法总结

### 复杂度总结

| 算法     | 最坏                 | 平均                 | 最好                 | 空间   | 方式        | 稳定性 |
| -------- | -------------------- | -------------------- | -------------------- | ------ | ----------- | ------ |
| 选择排序 | O(n<sup>2</sup>)     | O(n<sup>2</sup>)     | O(n<sup>2</sup>)     | O(1)   | `In-space`  | 不稳定 |
| 插入排序 | O(n<sup>2</sup>)     | O(n<sup>2</sup>)     | O(n)                 | O(1)   | `In-space`  | 稳定   |
| 冒泡排序 | O(n<sup>2</sup>)     | O(n<sup>2</sup>)     | O(n)                 | O(1)   | `In-space`  | 稳定   |
| 希尔排序 | O(n<sup>2</sup>)     | O(n<sup>1.5</sup>)   | O(n)                 | O(1)   | `In-space`  | 不稳定 |
| 快速排序 | O(n<sup>2</sup>)     | O(nlog<sub>2</sub>n) | O(nlog<sub>2</sub>n) | O(1)   | `In-space`  | 不稳定 |
| 堆排序   | O(nlog<sub>2</sub>n) | O(nlog<sub>2</sub>n) | O(nlog<sub>2</sub>n) | O(1)   | `In-space`  | 不稳定 |
| 归并排序 | O(nlog<sub>2</sub>n) | O(nlog<sub>2</sub>n) | O(nlog<sub>2</sub>n) | O(n)   | `Out-space` | 稳定   |
| 计数排序 | O(n+k)               | O(n+k)               | O(n+k)               | O(n+k) | `Out-space` | 稳定   |
| 桶排序   | O(n<sup>2</sup>)     | O(n+k)               | O(n)                 | O(n+k) | `Out-space` | 稳定   |
| 基数排序 | O(n*k)               | O(n*k)               | O(n*k)               | O(n+k) | `Out-space` | 稳定   |

