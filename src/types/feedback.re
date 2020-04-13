open Keybol;

type t =
  | NoFeedback
  | MsgFeedback(string);

let feedbackForKeybol = c =>
  switch (c) {
  | UDKey(k) => MsgFeedback(k ++ " is undefined")
  | _ => NoFeedback
  };
