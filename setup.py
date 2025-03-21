from setuptools import setup, Extension, find_packages
from setuptools.command.build_ext import build_ext
import subprocess
import os
from pathlib import Path

PROJECT_DIR = Path(__file__).parent

class CMakeBuildExt(build_ext):
    def initialize_options(self):
        super().initialize_options()
        self.build_type = "Release"
        
    def run(self):
        # 创建构建目录
        build_dir = os.path.abspath(self.build_temp)
        os.makedirs(build_dir, exist_ok=True)
        
        # 执行CMake构建
        subprocess.check_call(["cmake", "-S", ".", "-B", build_dir])
        subprocess.check_call(["cmake", "--build", build_dir, "--target", "boostpy"])
        
        # 将生成的文件复制到构建目录
        self.copy_tree(os.path.join(build_dir, "boostpy"), os.path.join(self.build_lib, "boostpy"))

setup(
    name="boostpy",
    version="0.0.1",
    author="Xiao",
    license="BSD-2-Clause",
    packages=find_packages(),
    # package_dir={"greeter": "greeter"},
    cmdclass={"build_ext": CMakeBuildExt},
    zip_safe=False,
    ext_modules=[Extension("boostpy", [])],
)