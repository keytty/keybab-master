open Command;

type t =
  | NoFeedback
  | MsgFeedback(string);

let feedbackForCommand = c =>
  switch (c) {
  | UDKey(k) => MsgFeedback(k ++ " is undefined")
  | _ => NoFeedback
  };
