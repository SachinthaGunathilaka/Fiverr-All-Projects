import matplotlib.pyplot as plt

x1 = [10, 100, 1000, 10000, 100000, 1000000]
# x1 = [10, 100, 1000, 10000, 100000]
selection_sort = [0.0109, 0.6766, 45.2899, 4108.9794, 970494.886, 233889054.109]
# selection_sort = [0.0109, 0.6766, 45.2899, 4108.9794, 970494.886]

# plt.figure(figsize=(14, 10))
# plt.plot(x1, selection_sort, label="selection sort", linestyle="-", color="blue")
# plt.title("Selection Sort Algorithm")
# plt.xlabel("Data Set Size")
# plt.ylabel("Execution Time (ms)")
# plt.savefig("selection_sort.png")

#
x2 = [10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000]
# x2 = [10, 100, 1000, 10000, 100000, 1000000, 10000000]
merge_sort = [0.0264, 0.5373, 4.5285, 69.9708, 918.1118, 10800.20, 132322.236, 1733418.71]
# merge_sort = [0.0264, 0.5373, 4.5285, 69.9708, 918.1118, 10800.20, 132322.236]
# plt.figure(figsize=(8, 6))
# plt.plot(x2, merge_sort, label="merge sort", linestyle="-", color="green")
# plt.title("Merge Sort Algorithm")
# plt.xlabel("Data Set Size")
# plt.ylabel("Execution Time (ms)")
#
# plt.savefig("merge_sort.png")



x3 = [10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000]
radix_sort = [0.024, 0.3123, 2.1874, 31.9771, 581.556, 8703.335, 103204.35, 1114603.66]
# plt.figure(figsize=(8, 6))
# plt.plot(x3, radix_sort, label="radix sort", linestyle="-", color="red")
# plt.title("Radix Sort Algorithm")
# plt.xlabel("Data Set Size")
# plt.ylabel("Execution Time (ms)")
# plt.savefig("radix_sort.png")


# plt.figure(figsize=(8, 6))
# plt.plot(x1, selection_sort, label="selection sort", linestyle="-", color="blue")
# plt.plot(x2, merge_sort, label="merge sort", linestyle="-", color="green")
# plt.plot(x3, radix_sort, label="radix sort", linestyle="-", color="red")
# plt.title("Sorting Algorithm Comparison")
# plt.xlabel("Data Set Size")
# plt.ylabel("Execution Time (ms)")
# plt.legend()
# plt.savefig("sorting_algorithm_comparison.png")


plt.figure(figsize=(8, 6))
plt.plot(x2, merge_sort, label="merge sort", linestyle="-", color="green")
plt.plot(x3, radix_sort, label="radix sort", linestyle="-", color="red")
plt.title("Merge Sort Vs Radix Sort")
plt.xlabel("Data Set Size")
plt.ylabel("Execution Time (ms)")
plt.legend()
plt.savefig("merge_sort_vs_radix_sort.png")


