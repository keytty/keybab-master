open Keybol;

type keybab = list(Keybol.t);

type cache = {
  looseDigits: keybab,
  drawerH: keybab,
  drawerJ: keybab,
  drawerK: keybab,
  drawerL: keybab,
  lastSymbol: option(Keybol.t),
};

type t = {
  added: list(Keybol.t),
  cache,
};

module Collapsor = {
  let safeHd = l =>
    switch (l->List.length) {
    | 0 => None
    | _ => Some(l->List.hd)
    };

  let collapseOneSet = (a: keybab, b: keybab): keybab => {
    let numberA = a |> Shifu.numerizeKeybab;
    let numberB = b |> Shifu.numerizeKeybab;
    let directionA = a |> List.rev |> safeHd;
    let directionB = b |> List.rev |> safeHd;

    switch (
      numberA,
      numberB,
      directionA == directionB,
      numberA > numberB,
      directionA,
      directionB,
    ) {
    | (0, 0, _, _, _, _) => []
    | (0, _, _, _, _, _) => b
    | (_, 0, _, _, _, _) => a
    | (_, _, true, _, Some(da), _) =>
      [numberA + numberB |> Shifu.numbersToKeybab, [da]] |> List.flatten
    | (_, _, false, true, Some(da), _) =>
      [numberA - numberB |> Shifu.numbersToKeybab, [da]] |> List.flatten
    | (_, _, false, false, _, Some(db)) =>
      [numberB - numberA |> Shifu.numbersToKeybab, [db]] |> List.flatten
    };
  };

  let collapse =
      (~vertical: (keybab, keybab), ~horizontal: (keybab, keybab))
      : (keybab, keybab) => {
    let (v1, v2) = vertical;
    let (h1, h2) = horizontal;

    (collapseOneSet(v1, v2), collapseOneSet(h1, h2));
  };

  let order = (lastSymbol: option(Keybol.t), chunk: (keybab, keybab)) => {
    let (v, h) = chunk;

    let hLastKeybol = h |> List.rev |> safeHd;

    hLastKeybol == lastSymbol ?
      [v, h] |> List.flatten : [h, v] |> List.flatten;
  };
};

let emptyCache = {
  looseDigits: [],
  drawerH: [],
  drawerJ: [],
  drawerK: [],
  drawerL: [],
  lastSymbol: None,
};

let zen = {added: [], cache: emptyCache};

let evaluateCache = c =>
  Collapsor.collapse(
    ~vertical=(c.drawerJ, c.drawerK),
    ~horizontal=(c.drawerH, c.drawerL),
  )
  |> Collapsor.order(c.lastSymbol)
  |> List.append(c.looseDigits);

let evaluate = ({added, cache}: t) =>
  if (cache == emptyCache) {
    added;
  } else {
    added |> List.append(evaluateCache(cache));
  };
