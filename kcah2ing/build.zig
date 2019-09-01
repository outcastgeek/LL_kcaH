const builtin = @import("builtin");
const std = @import("std");

const Builder = std.build.Builder;

pub fn build(b: *Builder) void {
    const mode = b.standardReleaseOptions();
    // const windows = b.option(bool, "windows", "create windows build") orelse false;
    const linux = b.option(bool, "linux", "create linux build") orelse false;
    // const macosx = b.option(bool, "macosx", "create macosx build") orelse false;
    
    const exe = b.addExecutable("datatype_sizes", null);
    exe.setBuildMode(mode);
    exe.linkSystemLibrary("c");
    // exe.install();

    const cflags = [][]const u8{
        "-std=c11",
        "-pedantic",
        "-Werror",
        "-Wall",
    };
    
    const csource_files = [][]const u8 {
        "signedunsignedlongshort/datatype_sizes.c"
    };

    for (csource_files) |csource| {
        exe.linkSystemLibrary("c");
        exe.addCSourceFile(csource, cflags);
    }

    // if (windows) {
    //     exe.setTarget(builtin.Arch.x86_64, builtin.Os.windows, builtin.Abi.gnu);
    // }

    if (linux) {
        exe.setTarget(builtin.Arch.x86_64, builtin.Os.linux, builtin.Abi.gnu);
    }

    // if (macosx) {
    //     exe.setTarget(builtin.Arch.x86_64, builtin.Os.macosx, builtin.Abi.gnu);
    // }

    b.default_step.dependOn(&exe.step);
    b.installArtifact(exe);
}

// zig build install --verbose-cc --prefix .
// zig build install --verbose-cc --prefix . -Dlinux=true
