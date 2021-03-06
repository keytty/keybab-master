open Action;

[@bs.deriving abstract]
type t = {
  [@bs.as "type"]
  type_: string,
  [@bs.optional]
  coordinates,
};

module Glossary = {
  let move = "move";
  let noaction = "noaction";
};

open Glossary;
let actionToStr =
  fun
  | Move(_) => move
  | NoAction => noaction;

let actionToJs = ac => {
  let actionStr = actionToStr(ac);

  switch (ac) {
  | Move({vertical: v, horizontal: h}) =>
    t(~type_=actionStr, ~coordinates={vertical: v, horizontal: h}, ())
  | NoAction => t(~type_=actionStr, ())
  };
};
