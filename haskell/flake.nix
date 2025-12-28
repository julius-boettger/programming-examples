{
  inputs = {
    # for ghc 9.8.4 as its the last version where the hls hlint plugin still works
    nixpkgs.url = "github:nixos/nixpkgs?rev=f4b140d5b253f5e2a1ff4e5506edbf8267724bde";
    systems.url = "github:nix-systems/default"; # can run on all systems
  };

  outputs = { self, nixpkgs, systems, ... }:
  let
    eachSystem = fn: nixpkgs.lib.genAttrs (import systems) (system: fn system (import nixpkgs {
      inherit system;
    }));
  in
  {
    devShells = eachSystem (system: pkgs: {
      default = pkgs.mkShell {
        packages = [
            (pkgs.ghc.withPackages (pkgs: with pkgs; [
              cabal-install # build system
              haskell-language-server # for vscode extension
            ]))
        ];
      };
    });
  };
}
