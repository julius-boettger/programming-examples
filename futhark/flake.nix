{
  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs/nixos-unstable";
    systems.url = "github:nix-systems/default"; # can run on all systems
  };

  outputs = { self, nixpkgs, systems, ... }:
  let
    eachSystem = fn: nixpkgs.lib.genAttrs (import systems) (system: fn system (import nixpkgs {
      inherit system;
      config.allowUnfree = true; # for cuda target
    }));
  in
  {
    devShells = eachSystem (system: pkgs: {
      default = pkgs.mkShell {
        packages = with pkgs; [
          futhark
          ispc # for ispc target
          opencl-headers ocl-icd # for opencl target
          cudatoolkit # for cuda target
        ];

        # more cuda stuff
        shellHook = ''
          export CUDA_PATH=${pkgs.cudatoolkit}
          export LIBRARY_PATH=${pkgs.cudatoolkit}/lib/stubs:$LIBRARY_PATH
          export LD_LIBRARY_PATH=/run/opengl-driver/lib:$LD_LIBRARY_PATH
        '';
      };
    });
  };
}
