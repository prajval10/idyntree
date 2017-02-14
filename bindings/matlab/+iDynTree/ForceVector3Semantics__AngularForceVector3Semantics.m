classdef ForceVector3Semantics__AngularForceVector3Semantics < iDynTree.GeomVector3Semantics__AngularForceVector3Semantics
  methods
    function self = ForceVector3Semantics__AngularForceVector3Semantics(varargin)
      self@iDynTree.GeomVector3Semantics__AngularForceVector3Semantics(SwigRef.Null);
      if nargin==1 && strcmp(class(varargin{1}),'SwigRef')
        if ~isnull(varargin{1})
          self.swigPtr = varargin{1}.swigPtr;
        end
      else
        tmp = iDynTreeMEX(438, varargin{:});
        self.swigPtr = tmp.swigPtr;
        tmp.swigPtr = [];
      end
    end
    function delete(self)
      if self.swigPtr
        iDynTreeMEX(441, self);
        self.swigPtr=[];
      end
    end
  end
  methods(Static)
    function varargout = compose(varargin)
     [varargout{1:nargout}] = iDynTreeMEX(439, varargin{:});
    end
    function varargout = inverse(varargin)
     [varargout{1:nargout}] = iDynTreeMEX(440, varargin{:});
    end
  end
end
