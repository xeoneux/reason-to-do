type item = {
  title: string,
  completed: bool,
};

type state = {items: list(item)};

let newItem = () => {title: "Click a button", completed: true};

let component = ReasonReact.reducerComponent("TodoApp");

let str = ReasonReact.stringToElement;

let make = _children => {
  ...component,
  initialState: () => {
    items: [{title: "Write some things to do", completed: false}],
  },
  reducer: ((), _) => ReasonReact.NoUpdate,
  render: ({state: {items}}) => {
    let numItems = List.length(items);
    <div className="app">
      <div className="title">
        (str("What to do"))
        <button onClick=(_event => Js.log("Didn't add something"))>
          (str("Add something"))
        </button>
      </div>
      <div className="items"> (str("Nothing")) </div>
      <div className="footer">
        (str(string_of_int(numItems) ++ " items"))
      </div>
    </div>;
  },
};
