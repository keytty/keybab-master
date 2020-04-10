open Action;

[@bs.deriving abstract]
type t = {
  [@bs.as "type"]
  type_: string,
  [@bs.optional]
  axis: string,
  [@bs.optional]
  amount: int,
};

module Glossary = {
  let move = "move";
  let noaction = "noaction";
  let vertical = "vertical";
  let horizontal = "horizontal";
};

let actionToStr =
  fun
  | Move(_) => Glossary.move
  | NoAction => Glossary.noaction;

let axisToStr =
  fun
  | Vertical => Glossary.vertical
  | Horizontal => Glossary.horizontal;

let actionToJs = ac => {
  let actionStr = actionToStr(ac);

  switch (ac) {
  | Move({axis: ax, amount: am}) =>
    t(~type_=actionStr, ~axis=axisToStr(ax), ~amount=am, ())
  | NoAction => t(~type_=actionStr, ())
  };
};
