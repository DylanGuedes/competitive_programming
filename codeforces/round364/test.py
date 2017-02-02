import subprocess
import resource

p = subprocess.Popen("./a.out")
p.wait()
print(resource.getrusage(resource.RUSAGE_CHILDREN).ru_maxrss)
